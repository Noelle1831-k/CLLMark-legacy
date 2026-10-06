"""Declarative, conflict-checked source rewriting on tree-sitter syntax trees.

A rule is three separate pieces instead of one function full of ``if`` filters:

* ``pattern`` - a tree-sitter query describing the structural shape of a candidate
  (node types, fields, child layout, literal tokens). Every pattern of a language is
  compiled into one query, so a tree is matched once, in C, for all rules.
* ``guards`` - named constraints for what a query cannot state: ancestors, text
  comparisons, collisions with other rules. Guards compose with ``&``, ``|`` and ``~``
  and ``Rule.explain`` reports which ones reject a node.
* ``rewrite`` - edits anchored to nodes (``replace``/``insert_before``/``delete``...).
  A rewrite that cannot handle a candidate raises ``Reject``; any other exception is a
  bug and propagates instead of being swallowed.

All edits of one candidate form an atomic group. Groups are applied in pre-order; a
group touching text already rewritten by an enclosing candidate is skipped, so nested
matches never corrupt each other. Offsets are UTF-8 byte offsets of the parsed source.
"""

import re
from bisect import bisect_left, bisect_right, insort
from collections import OrderedDict
from collections.abc import Callable, Iterable, Sequence
from dataclasses import dataclass
from typing import NamedTuple, Optional

from tree_sitter import Language, Node, Parser


def text(node: Node) -> str:
    return node.text.decode("utf-8")


class Reject(Exception):
    """The rewrite's precondition does not hold for this candidate."""


class Edit(NamedTuple):
    start: int
    end: int
    text: str = ""


def replace(node: Node, new_text: str) -> Edit:
    return Edit(node.start_byte, node.end_byte, new_text)


def insert_before(node: Node, new_text: str) -> Edit:
    return Edit(node.start_byte, node.start_byte, new_text)


def insert_after(node: Node, new_text: str) -> Edit:
    return Edit(node.end_byte, node.end_byte, new_text)


def delete(node: Node) -> Edit:
    return Edit(node.start_byte, node.end_byte)


def delete_between(start: int, end: int) -> Edit:
    return Edit(start, end)


class Source:
    """The code under rewrite; rewrites that lay out new lines read indentation from it."""

    __slots__ = ("code", "data")

    def __init__(self, code: str, data: bytes):
        self.code, self.data = code, data

    def indent(self, position: int, tab: int = 4) -> int:
        """Spaces (tab = `tab` columns) from the start of the line through `position`.

        This is the layout convention of the original rules: every blank before the
        node on its line counts, not only the leading indentation.
        """
        line = self.data[self.data.rfind(b"\n", 0, position) + 1 : position + 1]
        return line.count(b" ") + tab * line.count(b"\t")

    def leading(self, node: Node) -> str | None:
        """The whitespace before `node` on its line, or None when other text precedes it."""
        prefix = self.data[self.data.rfind(b"\n", 0, node.start_byte) + 1 : node.start_byte]
        return prefix.decode("utf-8") if not prefix.strip(b" \t") else None


class Guard:
    """A named predicate over a candidate node."""

    __slots__ = ("name", "test")

    def __init__(self, test: Callable[[Node], bool], name: str):
        self.test, self.name = test, name

    def __call__(self, node: Node) -> bool:
        return bool(self.test(node))

    def __and__(self, other: "Guard") -> "Guard":
        return Guard(lambda node: self(node) and other(node), f"({self.name} and {other.name})")

    def __or__(self, other: "Guard") -> "Guard":
        return Guard(lambda node: self(node) or other(node), f"({self.name} or {other.name})")

    def __invert__(self) -> "Guard":
        return Guard(lambda node: not self(node), f"not {self.name}")

    def __repr__(self) -> str:
        return f"Guard({self.name})"


def guard(name: str) -> Callable[[Callable[[Node], bool]], Guard]:
    return lambda test: Guard(test, name)


well_formed = Guard(lambda node: not node.has_error, "no parse errors in the candidate")


@dataclass(frozen=True)
class Matcher:
    """Nodes captured as ``@node`` by `pattern` that satisfy every guard."""

    pattern: str
    guards: tuple[Guard, ...] = ()

    def accepts(self, node: Node) -> bool:
        # Hot path (every candidate of every rule): a plain loop over the tests avoids a generator and a call layer.
        for check in self.guards:  # noqa: SIM110
            if not check.test(node):
                return False
        return True

    def explain(self, node: Node) -> list[str]:
        return [check.name for check in self.guards if not check(node)]

    def where(self, *guards: Guard) -> "Matcher":
        return Matcher(self.pattern, self.guards + guards)

    def rule(self, rewrite: Callable[[Node, "Source"], Sequence[Edit]], target: Optional["Matcher"] = None) -> "Rule":
        return Rule(self.pattern, self.guards, rewrite, target)


@dataclass(frozen=True)
class Rule(Matcher):
    """A rewrite applied to every accepted candidate; `target` recognizes the rewritten form."""

    rewrite: Callable[[Node, Source], Sequence[Edit]] | None = None  # always set by Matcher.rule
    target: Matcher | None = None


def apply_edits(data: bytes, groups: Iterable[Sequence[Edit]]) -> tuple[bytes, int]:
    """Apply atomic edit groups in order; returns the new bytes and the number of skipped groups.

    A group is skipped when one of its edits overlaps text replaced by an accepted group
    or inserts strictly inside it. Insertions at the same offset keep group order.
    """
    index = _AcceptedEdits()
    skipped = 0
    for group in groups:
        if any(index.conflicts(edit) for edit in group):
            skipped += 1
            continue
        index.accept(group)
    return _join(data, index), skipped


def apply_groups(data: bytes, groups: Sequence[Sequence[Edit]]) -> tuple[bytes, list[int]]:
    """`apply_edits` that reports the indices of the accepted groups instead of the number of skipped ones."""
    index = _AcceptedEdits()
    taken = []
    for position, group in enumerate(groups):
        if any(index.conflicts(edit) for edit in group):
            continue
        index.accept(group)
        taken.append(position)
    return _join(data, index), taken


def _join(data: bytes, index: "_AcceptedEdits") -> bytes:
    accepted = sorted(index.edits)
    parts, position = [], 0
    for start, end, _, new_text in accepted:
        if start < position:
            raise ValueError(f"Overlapping edits inside one rewrite at byte {start}")
        parts += [data[position:start], new_text.encode("utf-8")]
        position = end
    parts.append(data[position:])
    return b"".join(parts)


class _AcceptedEdits:
    """The edits accepted so far in one rewrite, with conflict queries in logarithmic time.

    Accepted replacements are normally disjoint, and then their ends are sorted like their starts: the only
    replacement that can overlap a query is the one starting closest before the query's end. Overlapping replacements
    (a rule bug, reported when the edits are applied) switch to comparing every pair, so outcomes never change.
    """

    def __init__(self) -> None:
        self.edits: list[tuple[int, int, int, str]] = []
        self.starts: list[int] = []
        self.ends: list[int] = []
        self.insertions: list[int] = []
        self.disjoint = True

    def _replacement_overlaps(self, start: int, end: int) -> bool:
        """Whether an accepted replacement [a, b) has a < end and b > start."""
        position = bisect_left(self.starts, end) - 1
        return position >= 0 and self.ends[position] > start

    def conflicts(self, edit: Edit) -> bool:
        if not self.disjoint:
            return any(_conflicts(edit, other) for other in self.edits)
        if edit.start == edit.end:
            return self._replacement_overlaps(edit.start, edit.start)
        position = bisect_right(self.insertions, edit.start)
        if position < len(self.insertions) and self.insertions[position] < edit.end:
            return True
        return self._replacement_overlaps(edit.start, edit.end)

    def accept(self, group: Sequence[Edit]) -> None:
        # Tie-break order of edits at the same span. The original read len(accepted) while extending the list with
        # this group, so the i-th edit got offset + 2*i; keeping that keeps same-offset insertions of different
        # groups in their established order.
        offset = len(self.edits)
        self.edits.extend((edit.start, edit.end, offset + 2 * order, edit.text) for order, edit in enumerate(group))
        for edit in group:
            if edit.start == edit.end:
                insort(self.insertions, edit.start)
            elif self.disjoint:
                if self._replacement_overlaps(edit.start, edit.end):
                    self.disjoint = False
                else:
                    position = bisect_left(self.starts, edit.start)
                    self.starts.insert(position, edit.start)
                    self.ends.insert(position, edit.end)


def _conflicts(edit: Edit, other: tuple[int, int, int, str]) -> bool:
    start, end = other[0], other[1]
    if edit.start == edit.end:
        return start < edit.start < end
    if start == end:
        return edit.start < start < edit.end
    return edit.start < end and start < edit.end


_PREDICATES = {"#eq?", "#not-eq?", "#match?"}


class Grammar:
    """A language's parser plus all its matchers compiled into one query."""

    def __init__(self, library: str, name: str, matchers: Iterable[Matcher], cache_size: int = 8):
        self.language = Language(library, name)
        self.parser = Parser()
        self.parser.set_language(self.language)
        self.matchers: dict[Matcher, int] = {}
        self._given = list(matchers)  # kept alive, so their ids in `_names` stay theirs
        for matcher in self._given:
            self.matchers.setdefault(matcher, len(self.matchers))
        # Capture name of each given matcher by identity: looking a frozen dataclass up rehashes all its fields.
        self._names = {id(matcher): f"m{self.matchers[matcher]}" for matcher in self._given}
        patterns = []
        for matcher, index in self.matchers.items():
            unsupported = set(re.findall(r"#[\w-]+\?", matcher.pattern)) - _PREDICATES
            if unsupported or "@node" not in matcher.pattern:
                raise ValueError(f"Pattern needs @node and only {sorted(_PREDICATES)}: {matcher.pattern}")
            patterns.append(re.sub(r"@node\b", f"@m{index}", matcher.pattern))
        self.query = self.language.query("\n".join(patterns))
        self._parsed: OrderedDict[str, Parsed] = OrderedDict()
        self._cache_size = cache_size

    def parse(self, code: str, tree=None) -> "Parsed":
        """The (cached) parse of `code`; `tree`, when given, is already the syntax tree of `code` (another query's,
        or one from `edited_tree`), so only this grammar's query runs."""
        parsed = self._parsed.get(code)
        if parsed is None:
            parsed = Parsed(self, code, tree)
            self._parsed[code] = parsed
            if len(self._parsed) > self._cache_size:
                self._parsed.popitem(last=False)
        else:
            self._parsed.move_to_end(code)
        return parsed


def _pre_order(node: Node) -> tuple[int, int]:
    return node.start_byte, -node.end_byte


class Parsed:
    """One parsed code version with its candidates per matcher (pre-order, deduplicated)."""

    def __init__(self, grammar: Grammar, code: str, tree=None):
        self.grammar = grammar
        self.source = Source(code, code.encode("utf-8"))
        self.tree = tree if tree is not None else grammar.parser.parse(self.source.data)
        groups: dict[str, dict[int, Node]] = {}
        for node, name in grammar.query.captures(self.tree.root_node):
            if name[0] == "m":
                group = groups.get(name)
                if group is None:
                    group = groups[name] = {}
                key = node.id
                if key not in group:
                    group[key] = node
        self._groups = groups
        self._sorted: dict[str, list[Node]] = {}
        # Guards and rewrites are functions of the tree, so their results hold for the life of this parse. Keyed by
        # identity, because hashing a frozen dataclass rehashes all its fields on every lookup; each entry keeps its
        # matcher, so an id cannot be reused by another object while the entry exists.
        self._accepted: dict[int, tuple[Matcher, list[Node]]] = {}
        self._edits: dict[int, tuple[Rule, list[tuple[Node, Sequence[Edit]]]]] = {}

    def captured(self, matcher: Matcher) -> list[Node]:
        """Nodes the matcher's pattern captures, in pre-order (outer before inner), before its guards.

        Sorted on first use: most parsed versions are only queried for one or two matchers.
        """
        name = self.grammar._names.get(id(matcher)) or f"m{self.grammar.matchers[matcher]}"
        nodes = self._sorted.get(name)
        if nodes is None:
            group = self._groups.get(name)
            nodes = self._sorted[name] = sorted(group.values(), key=_pre_order) if group else []
        return nodes

    def candidates(self, matcher: Matcher) -> list[Node]:
        """Captured nodes that satisfy every guard, in pre-order (computed once per matcher)."""
        entry = self._accepted.get(id(matcher))
        if entry is None:
            accepts = matcher.accepts
            entry = self._accepted[id(matcher)] = (matcher, [node for node in self.captured(matcher) if accepts(node)])
        return entry[1]

    def edits(self, rule: Rule) -> list[tuple[Node, Sequence[Edit]]]:
        """Each candidate of `rule` with its edit group, in pre-order; the group is empty when the rewrite rejects
        the candidate or has nothing to change."""
        entry = self._edits.get(id(rule))
        if entry is None:
            rewrite = rule.rewrite
            if rewrite is None:
                raise ValueError(f"Rule without a rewrite: {rule.pattern}")
            result = []
            for node in self.candidates(rule):
                try:
                    group = rewrite(node, self.source) or ()
                except Reject:
                    group = ()
                result.append((node, group))
            entry = self._edits[id(rule)] = (rule, result)
        return entry[1]

    def rewrite(self, rule: Rule) -> tuple[str, int, bool]:
        """Rewritten code, the number of candidates, and whether the code changed beyond spaces and line breaks.

        Reuses the edit groups of `edits` when they were collected (node slots read every candidate's group); file
        granularity asks once per rule and parse, so it rewrites directly instead of building them.
        """
        entry = self._edits.get(id(rule))
        if entry is not None:
            count, groups = len(entry[1]), [group for _, group in entry[1] if group]
        else:
            rewrite = rule.rewrite
            if rewrite is None:
                raise ValueError(f"Rule without a rewrite: {rule.pattern}")
            nodes = self.candidates(rule)
            count, groups = len(nodes), []
            for node in nodes:
                try:
                    edits = rewrite(node, self.source)
                except Reject:
                    continue
                if edits:
                    groups.append(edits)
        if not groups:
            return self.source.code, count, False
        old = self.source.data
        data, _ = apply_edits(old, groups)
        return data.decode("utf-8"), count, data != old and _beyond_whitespace(old, data, groups)

    def apply(self, groups: Sequence[Sequence[Edit]]) -> str:
        """The code with the given edit groups applied (later groups that conflict with earlier ones are skipped)."""
        if not groups:
            return self.source.code
        return apply_edits(self.source.data, groups)[0].decode("utf-8")


def _point(data: bytes, position: int) -> tuple[int, int]:
    """Tree-sitter point (row, byte column) of a byte offset."""
    return data.count(b"\n", 0, position), position - (data.rfind(b"\n", 0, position) + 1)


def edited_tree(parser: Parser, tree, old: bytes, new: bytes, edits: Sequence[Edit]):
    """The syntax tree of `new` (`old` with the accepted `edits` applied), parsed incrementally from `tree`, the tree
    of `old`, which stays as it is: an incremental parse without edits first gives a private tree that shares all
    subtrees, and only that one is edited. Edits are told to the tree from the last one back, so the offsets and
    points of the earlier ones still hold."""
    private = parser.parse(old, tree)
    for edit in sorted(edits, key=lambda edit: (edit.start, edit.end), reverse=True):
        text = edit.text.encode("utf-8")
        start = _point(old, edit.start)
        lines = text.count(b"\n")
        end_column = len(text) - text.rfind(b"\n") - 1 if lines else start[1] + len(text)
        private.edit(
            start_byte=edit.start,
            old_end_byte=edit.end,
            new_end_byte=edit.start + len(text),
            start_point=start,
            old_end_point=_point(old, edit.end),
            new_end_point=(start[0] + lines, end_column),
        )
    return parser.parse(new, private)


def changes_beyond_whitespace(data: bytes, group: Sequence[Edit]) -> bool:
    """Whether applying the one edit group to `data` changes it beyond spaces and line breaks.

    Only the group's window is rewritten and compared (see `_beyond_whitespace`); a single group is never skipped.
    """
    if not group:
        return False
    start = min(edit.start for edit in group)
    end = max(edit.end for edit in group)
    before = data[start:end]
    after, _ = apply_edits(before, [[Edit(edit.start - start, edit.end - start, edit.text) for edit in group]])
    return after != before and before.translate(None, b" \n") != after.translate(None, b" \n")


def _beyond_whitespace(old: bytes, new: bytes, groups: Sequence[Sequence[Edit]]) -> bool:
    """Whether `new` differs from `old` once spaces and line breaks are removed, comparing only the edited window.

    Every edit lies in [start, end), so new = old[:start] + window + old[end:]. Removing characters distributes over
    concatenation, so the whole texts agree without spaces and line breaks exactly when the two windows do. Both
    bytes are UTF-8, where a space or line feed byte is always that character.
    """
    start = min(edit.start for group in groups for edit in group)
    end = max(edit.end for group in groups for edit in group)
    before, after = old[start:end], new[start : len(new) - (len(old) - end)]
    return before.translate(None, b" \n") != after.translate(None, b" \n")

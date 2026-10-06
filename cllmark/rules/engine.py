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
        return all(check(node) for check in self.guards)

    def explain(self, node: Node) -> list[str]:
        return [check.name for check in self.guards if not check(node)]

    def where(self, *guards: Guard) -> "Matcher":
        return Matcher(self.pattern, self.guards + guards)

    def rule(self, rewrite: Callable[[Node, "Source"], Sequence[Edit]], target: Optional["Matcher"] = None) -> "Rule":
        return Rule(self.pattern, self.guards, rewrite, target)


@dataclass(frozen=True)
class Rule(Matcher):
    """A rewrite applied to every accepted candidate; `target` recognizes the rewritten form."""

    rewrite: Callable[[Node, Source], Sequence[Edit]] = None
    target: Matcher | None = None


def apply_edits(data: bytes, groups: Iterable[Sequence[Edit]]) -> tuple[bytes, int]:
    """Apply atomic edit groups in order; returns the new bytes and the number of skipped groups.

    A group is skipped when one of its edits overlaps text replaced by an accepted group
    or inserts strictly inside it. Insertions at the same offset keep group order.
    """
    accepted: list[tuple[int, int, int, str]] = []
    skipped = 0
    for group in groups:
        if any(_conflicts(edit, other) for edit in group for other in accepted):
            skipped += 1
            continue
        accepted.extend((edit.start, edit.end, len(accepted) + index, edit.text) for index, edit in enumerate(group))
    accepted.sort()
    parts, position = [], 0
    for start, end, _, new_text in accepted:
        if start < position:
            raise ValueError(f"Overlapping edits inside one rewrite at byte {start}")
        parts += [data[position:start], new_text.encode("utf-8")]
        position = end
    parts.append(data[position:])
    return b"".join(parts), skipped


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
        for matcher in matchers:
            self.matchers.setdefault(matcher, len(self.matchers))
        patterns = []
        for matcher, index in self.matchers.items():
            unsupported = set(re.findall(r"#[\w-]+\?", matcher.pattern)) - _PREDICATES
            if unsupported or "@node" not in matcher.pattern:
                raise ValueError(f"Pattern needs @node and only {sorted(_PREDICATES)}: {matcher.pattern}")
            patterns.append(re.sub(r"@node\b", f"@m{index}", matcher.pattern))
        self.query = self.language.query("\n".join(patterns))
        self._parsed: OrderedDict[str, Parsed] = OrderedDict()
        self._cache_size = cache_size

    def parse(self, code: str) -> "Parsed":
        parsed = self._parsed.get(code)
        if parsed is None:
            parsed = Parsed(self, code)
            self._parsed[code] = parsed
            if len(self._parsed) > self._cache_size:
                self._parsed.popitem(last=False)
        else:
            self._parsed.move_to_end(code)
        return parsed


class Parsed:
    """One parsed code version with its candidates per matcher (pre-order, deduplicated)."""

    def __init__(self, grammar: Grammar, code: str):
        self.grammar = grammar
        self.source = Source(code, code.encode("utf-8"))
        self.tree = grammar.parser.parse(self.source.data)
        captured: dict[str, dict[int, Node]] = {}
        for node, name in grammar.query.captures(self.tree.root_node):
            if name[0] == "m":
                captured.setdefault(name, {}).setdefault(node.id, node)
        self._captured = {
            name: sorted(nodes.values(), key=lambda n: (n.start_byte, -n.end_byte)) for name, nodes in captured.items()
        }

    def candidates(self, matcher: Matcher) -> list[Node]:
        nodes = self._captured.get(f"m{self.grammar.matchers[matcher]}", [])
        return [node for node in nodes if matcher.accepts(node)]

    def rewrite(self, rule: Rule) -> tuple[str, int]:
        """Rewritten code and the number of candidates."""
        nodes = self.candidates(rule)
        groups = []
        for node in nodes:
            try:
                edits = rule.rewrite(node, self.source)
            except Reject:
                continue
            if edits:
                groups.append(edits)
        if not groups:
            return self.source.code, len(nodes)
        data, _ = apply_edits(self.source.data, groups)
        return data.decode("utf-8"), len(nodes)

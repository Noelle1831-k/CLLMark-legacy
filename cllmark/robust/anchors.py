"""Observation of the sites of a project with position-free anchor keys and a self-stability check.

A site is a node of a rule pair that either style rewrites (`cllmark.nodes.sites`). Its anchor key is a hash of the
site's own context, never of its position, file name or support file:

* `tok` (A-tok): the pair name, the name of the enclosing function, and the set of identifiers and literals inside the
  site's node. String literals count by decoded content; names that rules introduce or delete (I/O functions,
  `std`, `list`, ...) are left out (`STOP_NAMES`). Reformatting, reordering and our own rewrites keep it; renaming
  changes it.
* `struct` (A-struct): the pair name and a digest of the node's structural skeleton: identifiers become `ID`, numbers
  stay, strings count by content, comparison/equality/compound-assignment operators count by family, parentheses,
  negations and comments are transparent, and the operands of commutative operators and the branches of conditionals are
  sorted. Renaming keeps it; different places collide more often.

A site is *stable* when its key does not change if the site is rewritten alone to its other reading, nor when the
file's sites are set to pseudo-random targets together (`_stable`). Unstable sites are neither embedded nor counted.
Sites without a rewrite that changes the code beyond whitespace (not usable) cannot be checked and are not stable.
"""

from __future__ import annotations

import hashlib
import re
import weakref
from collections import OrderedDict
from collections.abc import Mapping
from dataclasses import dataclass
from typing import NamedTuple

from .. import nodes
from ..source_io import reload_written
from ..transform import StyleTransformer
from ..watermark import project_order
from .keys import ANCHORS


# Names of library functions, namespaces and builtins that rules write or remove; they never name a site.
def _names(text: str) -> frozenset[str]:
    return frozenset(text.split())


STOP_NAMES: dict[str, frozenset[str]] = {
    "python": _names(
        "print list dict tuple range len sum str int float set sorted enumerate min max abs map zip True False None "
        "sys stdout flush end sep file main"
    ),
    "c": _names(
        "printf scanf puts putchar getchar sizeof malloc calloc free memset main argc argv NULL stdin stdout identifier"
    ),
    "cpp": _names(
        "printf scanf puts putchar getchar cout cin endl std main argc argv NULL nullptr cerr stdin stdout identifier"
    ),
    "javascript": _names(
        "Number Math Array Object parseInt parseFloat undefined main argc argv console log length pow isNaN "
        "String Boolean"
    ),
}

_STRING_TYPES = frozenset(
    {"string", "string_literal", "char_literal", "raw_string_literal", "template_string", "concatenated_string"}
)
_NUMBER_TYPES = frozenset(
    {"number_literal", "integer", "float", "number", "integer_literal", "float_literal", "imaginary_literal"}
)
_SKIPPED_TYPES = frozenset({"comment", "ERROR"})
_FUNCTIONS = {
    "python": frozenset({"function_definition"}),
    "c": frozenset({"function_definition"}),
    "cpp": frozenset({"function_definition"}),
    "javascript": frozenset(
        {
            "function_declaration",
            "generator_function_declaration",
            "function",
            "function_expression",
            "generator_function",
            "method_definition",
            "arrow_function",
        }
    ),
}
_ESCAPES = {"n": "\n", "t": "\t", "r": "\r", "0": "\0", "\\": "\\", "'": "'", '"': '"', "`": "`"}
_QUOTES = ('"""', "'''", '"', "'", "`")

STABILITY_ROUNDS = 8  # random-target rounds at most (a round takes one non-overlapping set of the file's sites)
CACHE_SIZE = 512  # versions of files whose observations are kept per transformer


@dataclass(frozen=True)
class Observation:
    file: str
    pair: str
    index: int  # index among the file's sites of the pair (as in `cllmark.nodes`)
    reading: int | None
    usable: bool
    stable: bool
    window: tuple[int, int]
    key: str  # anchor key, hex


class Entry(NamedTuple):
    """One site of one file version: the node-level `Site`, its key and whether the key is stable."""

    pair: str
    index: int
    site: nodes.Site
    key: str
    stable: bool


# ------------------------------------------------------------------------------------------------ keys


def _unescape(text: str) -> str:
    return re.sub(r"\\(.)", lambda match: _ESCAPES.get(match.group(1), match.group(0)), text, flags=re.S)


def string_value(text: str) -> str:
    """The decoded content of a string literal's source text (prefix letters, quotes and escapes removed)."""
    start = 0
    while start < len(text) and text[start] not in "\"'`":
        start += 1
    body = text[start:]
    for quote in _QUOTES:
        if len(body) >= 2 * len(quote) and body.startswith(quote) and body.endswith(quote):
            body = body[len(quote) : len(body) - len(quote)]
            break
    return _unescape(body)


def _node_of(root, span: tuple[int, int]):
    """The outermost node with exactly `span` (a candidate may share its span with wrappers)."""
    node = root.descendant_for_byte_range(span[0], span[1])
    while node is not None and (node.start_byte, node.end_byte) != span:
        node = node.parent
    if node is None:
        return None
    while node.parent is not None and (node.parent.start_byte, node.parent.end_byte) == span:
        node = node.parent
    return node


def _declared_name(function) -> str | None:
    """The name a function node declares, or is bound to (`const f = () => ...`, `{f: function () {}}`)."""
    name = function.child_by_field_name("name")
    if name is not None:
        return name.text.decode("utf-8")
    declarator = function.child_by_field_name("declarator")
    if declarator is not None:  # C and C++: unwrap pointer/function declarators
        while declarator is not None and declarator.child_by_field_name("declarator") is not None:
            declarator = declarator.child_by_field_name("declarator")
        return declarator.text.decode("utf-8") if declarator is not None else None
    parent = function.parent
    if parent is not None:
        for field in ("name", "key", "left"):
            bound = parent.child_by_field_name(field)
            if bound is not None and bound.type in ("identifier", "property_identifier", "string"):
                return bound.text.decode("utf-8")
    return None


def function_name(node, language: str) -> str:
    """The name of the nearest enclosing function that has one ("" at the top level)."""
    types = _FUNCTIONS[language]
    parent = node.parent
    while parent is not None:
        if parent.type in types:
            name = _declared_name(parent)
            if name:
                return name
        parent = parent.parent
    return ""


def tokens(node, language: str) -> list[str]:
    """Sorted distinct `kind:text` of the identifiers, numbers and strings inside `node` (stop names left out)."""
    stop = STOP_NAMES[language]
    found: set[str] = set()
    stack = [node]
    while stack:
        current = stack.pop()
        kind = current.type
        if kind in _SKIPPED_TYPES:
            continue
        if kind in _STRING_TYPES:
            if kind == "concatenated_string":
                stack.extend(current.children)
            else:
                found.add("s:" + string_value(current.text.decode("utf-8")))
        elif kind in _NUMBER_TYPES:
            found.add("n:" + current.text.decode("utf-8"))
        elif kind == "property_identifier":  # `o.p` and `o["p"]` name the same property
            found.add("s:" + current.text.decode("utf-8"))
        elif kind == "identifier" or kind.endswith("_identifier"):
            name = current.text.decode("utf-8")
            if name not in stop:
                found.add("i:" + name)
        elif current.child_count:
            stack.extend(current.children)
    return sorted(found)


# Operator families of the skeleton (rule families: comparison, equality, compound assignment).
_COMPARISON = {"<", ">", "<=", ">="}
_EQUALITY = {"==", "!=", "===", "!=="}
_COMPOUND = {"+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", "**=", "//=", "||=", "&&=", "??=", "@="}
_MEMBERSHIP = {"in", "not in"}
_IDENTITY = {"is", "is not"}
_FAMILY = (
    dict.fromkeys(_COMPARISON, "CMP")
    | dict.fromkeys(_EQUALITY, "EQ")
    | dict.fromkeys(_COMPOUND, "OPASSIGN")
    | dict.fromkeys(_MEMBERSHIP, "IN")
    | dict.fromkeys(_IDENTITY, "IS")
)
_OPERATORS = set(_FAMILY) | {
    "+",
    "-",
    "*",
    "/",
    "%",
    "&",
    "|",
    "^",
    "<<",
    ">>",
    "&&",
    "||",
    "and",
    "or",
    "**",
    "//",
    "=",
    "??",
}
_COMMUTATIVE = {"CMP", "EQ", "IN", "IS", "+", "*", "&", "|", "^", "&&", "||", "and", "or"}
_BINARY = frozenset({"binary_expression", "binary_operator", "boolean_operator", "comparison_operator"})
_NEGATIONS = frozenset({"not_operator"})
_TRANSPARENT = frozenset({"parenthesized_expression", "else_clause", "expression_list"})
_FUNCTION_BODIES = frozenset(
    {
        "function_definition",
        "function_declaration",
        "function",
        "function_expression",
        "arrow_function",
        "method_definition",
        "generator_function",
        "generator_function_declaration",
    }
)
_CONDITIONALS = frozenset({"conditional_expression", "ternary_expression"})


def _hash(*parts: bytes | str) -> bytes:
    digest = hashlib.blake2b(digest_size=16)
    for part in parts:
        digest.update(part.encode("utf-8") if isinstance(part, str) else part)
        digest.update(b"\x00")
    return digest.digest()


def _is_negation(node) -> bool:
    if node.type in _NEGATIONS:
        return True
    return node.type == "unary_expression" and any(child.type == "!" for child in node.children if not child.is_named)


def _is_print_option(node) -> bool:
    """`flush=True` / `end=""` arguments, which the print rules add and remove."""
    if node.type != "keyword_argument":
        return False
    name = node.child_by_field_name("name")
    return name is not None and name.text in (b"flush", b"end")


def _leaf_digest(node) -> bytes | None:
    """The digest of a node that is a leaf of the skeleton (b"" when it is dropped), None for inner nodes."""
    kind = node.type
    if kind in _SKIPPED_TYPES:
        return b""
    if kind in _STRING_TYPES:
        return _hash("S", string_value(node.text.decode("utf-8")))
    if kind in _NUMBER_TYPES:
        return _hash("N", node.text.decode("utf-8"))
    if kind == "property_identifier":  # `o.p` and `o["p"]` (see `_special`)
        return _hash("S", node.text.decode("utf-8"))
    if kind == "identifier" or kind.endswith("_identifier"):
        return _hash("ID")
    if node.child_count == 0:
        return _hash("L", kind, node.text.decode("utf-8")) if node.is_named else b""
    return None


def _strip(node):
    while node is not None and node.type == "parenthesized_expression" and node.named_child_count == 1:
        node = node.named_children[0]
    return node


def _operator(node) -> str | None:
    operator = node.child_by_field_name("operator")
    return operator.type if operator is not None else None


def _special(node, language: str) -> bytes | None:
    """Digests that equate the two forms of a rule pair whose forms differ in tree shape (None for other nodes).

    `x += y` and `x = x + y`; `a <= b` and `(a < b || a == b)`; `a[i]` and `*(a + i)`; `p->x` and `(*p).x`;
    JavaScript `o.p` and `o["p"]` (see `_leaf_digest`), `while (c) S` and `for (; c; ) S`.
    """
    kind = node.type

    def digest(child) -> bytes:
        return _skeleton_digest(child, language)

    if kind in ("augmented_assignment", "augmented_assignment_expression") or (
        kind == "assignment_expression" and _operator(node) in _COMPOUND
    ):
        left, right = node.child_by_field_name("left"), node.child_by_field_name("right")
        if left is not None and right is not None:
            return _hash("T", "SELFASSIGN", digest(left), digest(right))
    elif kind in ("assignment_expression", "assignment"):
        left, right = node.child_by_field_name("left"), _strip(node.child_by_field_name("right"))
        if left is not None and right is not None and right.type in _BINARY:
            first, second = right.child_by_field_name("left"), right.child_by_field_name("right")
            if first is not None and second is not None and digest(left) == digest(first):
                return _hash("T", "SELFASSIGN", digest(left), digest(second))
    elif kind in ("binary_expression", "boolean_operator"):
        if _operator(node) in ("||", "or", "&&", "and"):
            sides = [_strip(node.child_by_field_name("left")), _strip(node.child_by_field_name("right"))]
            if all(side is not None and side.type in _BINARY for side in sides):
                found = {}
                for side in sides:
                    if side.type == "comparison_operator":  # Python: operands are the named children
                        operator = next((c.type for c in side.children if c.type in _FAMILY), None)
                        operands = side.named_children if side.named_child_count == 2 else [None]
                    else:
                        operator = _operator(side)
                        operands = [side.child_by_field_name("left"), side.child_by_field_name("right")]
                    if None in operands or operator is None:
                        break
                    found[_FAMILY.get(operator)] = sorted(digest(operand) for operand in operands)
                else:
                    if set(found) == {"CMP", "EQ"} and found["CMP"] == found["EQ"]:
                        form = "comparison_operator" if language == "python" else "binary_expression"
                        return _hash("T", form, "CMP", *found["CMP"])
    elif kind == "pointer_expression" and language in ("c", "cpp"):
        operand = _strip(node.child_by_field_name("argument"))
        terms = []  # a + i + j is (a + i) + j: the base is the first term, the index the sum of the others
        while operand is not None and operand.type == "binary_expression" and _operator(operand) == "+":
            terms.append(operand.child_by_field_name("right"))
            operand = operand.child_by_field_name("left")
        if operand is not None and terms and None not in terms and len(terms) <= 2:
            terms = [digest(term) for term in reversed(terms)]
            index = terms[0] if len(terms) == 1 else _hash("T", "binary_expression", "+", *sorted(terms))
            return _hash("T", "subscript_expression", "", digest(operand), index)
    elif kind == "field_expression":
        argument = _strip(node.child_by_field_name("argument"))
        field = node.child_by_field_name("field")
        if (
            argument is not None
            and field is not None
            and argument.type == "pointer_expression"
            and any(child.type == "*" for child in argument.children)
        ):
            inner = argument.child_by_field_name("argument")
            if inner is not None:
                return _hash("T", "field_expression", "", digest(inner), digest(field))
    elif kind == "for_statement" and language == "javascript":
        initializer, condition = node.child_by_field_name("initializer"), node.child_by_field_name("condition")
        body = node.child_by_field_name("body")
        if (
            initializer is not None
            and initializer.type == "empty_statement"
            and node.child_by_field_name("increment") is None
            and condition is not None
            and condition.named_child_count == 1
            and body is not None
        ):
            return _hash("T", "while_statement", "", digest(condition.named_children[0]), digest(body))
    elif kind == "call" and language == "python":
        function, arguments = node.child_by_field_name("function"), node.child_by_field_name("arguments")
        if (
            function is not None
            and function.type == "identifier"
            and function.text == b"list"
            and arguments is not None
        ):
            if arguments.named_child_count == 0:
                return _hash("T", "list", "")
            if arguments.named_child_count == 1 and arguments.named_children[0].type == "list":
                return digest(arguments.named_children[0])
    elif kind == "return_statement" and language == "python":
        if node.named_child_count == 1 and node.named_children[0].type == "none":
            return _hash("T", "return_statement", "")
    elif kind == "array_declarator" and language in ("c", "cpp"):
        if node.child_by_field_name("size") is None and node.child_by_field_name("declarator") is not None:
            return _hash("T", "pointer_declarator", "*", digest(node.child_by_field_name("declarator")))
    elif kind == "cast_expression" and language == "cpp":
        cast_type, value = node.child_by_field_name("type"), node.child_by_field_name("value")
        if cast_type is not None and value is not None:
            return _hash("T", "CAST", cast_type.text.decode("utf-8"), digest(value))
    elif kind == "call_expression" and language == "cpp":
        function, arguments = node.child_by_field_name("function"), node.child_by_field_name("arguments")
        if (
            function is not None
            and function.type == "primitive_type"
            and arguments is not None
            and arguments.named_child_count == 1
        ):
            return _hash("T", "CAST", function.text.decode("utf-8"), digest(arguments.named_children[0]))
    elif kind == "return_statement" and node.named_child_count == 0 and language != "python":
        parent = node.parent  # a final `return;` of a function is dropped (void_return)
        if (
            parent is not None
            and parent.type in ("compound_statement", "statement_block")
            and parent.parent is not None
            and parent.parent.type in _FUNCTION_BODIES
            and parent.named_children[-1].id == node.id
        ):
            return b""
    elif kind == "while_statement" and language == "python":
        condition, body = node.child_by_field_name("condition"), node.child_by_field_name("body")
        if condition is not None and condition.type == "true" and body is not None and body.named_child_count > 1:
            first = body.named_children[0]  # while True: if not C: break  S...  ==  while C: S...
            if first.type == "if_statement" and first.child_by_field_name("alternative") is None:
                test, consequence = first.child_by_field_name("condition"), first.child_by_field_name("consequence")
                if (
                    test is not None
                    and test.type == "not_operator"
                    and consequence is not None
                    and consequence.named_child_count == 1
                    and consequence.named_children[0].type == "break_statement"
                ):
                    rest = [digest(child) for child in body.named_children[1:]]
                    block = _hash("T", "block", "", *[item for item in rest if item])
                    return _hash("T", "while_statement", "", digest(test.child_by_field_name("argument")), block)
    return None


def _combine(node, operators: list[str], children: list[bytes], language: str) -> bytes:
    kind = node.type
    special = _special(node, language)
    if special is not None:
        return special
    digests = [digest for digest in children if digest]
    if (kind in _TRANSPARENT or _is_negation(node)) and len(digests) == 1:
        return digests[0]
    if kind in _BINARY and operators and all(op in _COMMUTATIVE for op in operators):
        digests = sorted(digests)
    elif kind in _CONDITIONALS and len(digests) == 3:
        # a ? b : c and its negated swap: the condition and the sorted branches
        if language == "python":  # b if a else c
            condition, branches = digests[1], [digests[0], digests[2]]
        else:
            condition, branches = digests[0], digests[1:]
        digests = [condition, *sorted(branches)]
    elif kind == "if_statement" and any(child.type == "else_clause" for child in node.children):
        # if c: A else: B  and  if not c: B else: A: the condition leads, the two branches are sorted
        digests = digests[:1] + sorted(digests[1:])
    if kind == "member_expression":
        kind = "subscript_expression"
    elif kind == "expression_list":
        kind = "tuple"
    return _hash("T", kind, ",".join(operators), *digests)


def _skeleton_digest(node, language: str) -> bytes:
    """The structural digest of `node`, computed without recursion (deep expression chains are common)."""
    stack = [[node, None, 0, [], []]]  # [node, named children, position, child digests, operator families]
    while True:
        frame = stack[-1]
        current = frame[0]
        if frame[1] is None:
            leaf = _leaf_digest(current)
            if leaf is not None:
                stack.pop()
                if not stack:
                    return leaf
                stack[-1][3].append(leaf)
                continue
            frame[1] = [child for child in current.children if child.is_named and not _is_print_option(child)]
            frame[4] = [
                _FAMILY.get(child.type, child.type)
                for position, child in enumerate(current.children)
                if not child.is_named
                and child.type in _OPERATORS
                # `not in` and `is not` are two tokens of one type
                and not (
                    position
                    and child.type in ("not in", "is not")
                    and current.children[position - 1].type == child.type
                )
            ]
        if frame[2] < len(frame[1]):
            frame[2] += 1
            stack.append([frame[1][frame[2] - 1], None, 0, [], []])
            continue
        stack.pop()
        digest = _combine(current, frame[4], frame[3], language)
        if not stack:
            return digest
        stack[-1][3].append(digest)


def anchor_key(language: str, anchor: str, pair: str, root, span: tuple[int, int]) -> str:
    """The hex anchor key of the node of `root` at `span` ("" digest of the pair alone when the node is missing)."""
    if anchor not in ANCHORS:
        raise ValueError(f"anchor must be one of {ANCHORS}: {anchor!r}")
    node = _node_of(root, span)
    if node is None:
        return _hash(anchor, pair, "missing").hex()
    if anchor == "tok":
        return _hash("tok", pair, function_name(node, language), *tokens(node, language)).hex()
    return _hash("struct", pair, _skeleton_digest(node, language)).hex()


# ------------------------------------------------------------------------------------------------ observation

_KEYS: weakref.WeakKeyDictionary = weakref.WeakKeyDictionary()  # transformer -> {(anchor, code): entries}


class Entries(tuple):
    """The entries of one file version; `errors` counts the rule pairs whose rules raised on it (such a pair has no
    sites in the file, as in `cllmark.nodes`)."""

    errors: int = 0


def _site_entries(transformer: StyleTransformer, language: str, anchor: str, code: str) -> Entries:
    """Every site of every pair of `code` with its key; `stable` is False until `_stable` has decided."""
    root = None
    entries = []
    errors = 0
    for pair, styles in transformer.pairs.items():
        found = nodes._sites_or_none(transformer, styles, code)
        if found is None:
            errors += 1
            continue
        if not found:
            continue
        if root is None:
            root = transformer.grammar.parse(code).tree.root_node
        for index, site in enumerate(found):
            key = anchor_key(language, anchor, pair, root, (site.start, site.end))
            entries.append(Entry(pair, index, site, key, False))
    result = Entries(entries)
    result.errors = errors
    return result


def _stable_targets(code: str, pair: str, index: int) -> int:
    """A pseudo-random target bit for a site (fixed by the code, so analysis and checks agree)."""
    return hashlib.blake2b(f"{pair}:{index}:{code}".encode(), digest_size=1).digest()[0] & 1


_NAME = "f"


def _key_after(
    transformer: StyleTransformer, language: str, anchor: str, text: str, final: tuple[str, str, int]
) -> str | None:
    pair, index = final[1], final[2]
    found = nodes._sites_or_none(transformer, transformer.pairs[pair], text)
    if not found or index >= len(found):
        return None
    root = transformer.grammar.parse(text).tree.root_node
    return anchor_key(language, anchor, pair, root, (found[index].start, found[index].end))


def _place(transformer: StyleTransformer, language: str, code: str, assignments):
    try:
        return nodes.place(transformer, language, {_NAME: code}, assignments)
    except Exception:  # a rule that raises on the rewritten code makes the site unusable
        return {}, {slot: None for slot, _ in assignments}


def _stable(transformer: StyleTransformer, language: str, anchor: str, code: str, entries: list[Entry]) -> set:
    """(pair, index) of the sites whose key survives their own flip and a joint random rewrite of the file."""
    usable = [entry for entry in entries if entry.site.usable]
    alive = {}
    for entry in usable:  # alone: both readings must give the same key
        slot = (_NAME, entry.pair, entry.index)
        written, located = _place(transformer, language, code, [(slot, 1 - entry.site.reading)])
        final = located.get(slot)
        if final is None:
            continue
        text = reload_written(written.get(_NAME, code))
        if _key_after(transformer, language, anchor, text, final) == entry.key:
            alive[(entry.pair, entry.index)] = entry
    remaining = sorted(alive.values(), key=lambda entry: (entry.site.start, -entry.site.end, entry.pair))
    stable = set(alive)
    for _ in range(STABILITY_ROUNDS):
        if not remaining:
            break
        regions = nodes._Regions()
        chosen, rest = [], []
        for entry in remaining:
            slot = (_NAME, entry.pair, entry.index)
            (chosen if regions.take(entry.site, slot) else rest).append(entry)
        assignments = [
            ((_NAME, entry.pair, entry.index), _stable_targets(code, entry.pair, entry.index)) for entry in chosen
        ]
        written, located = _place(transformer, language, code, assignments)
        text = reload_written(written.get(_NAME, code))
        for entry in chosen:
            final = located.get((_NAME, entry.pair, entry.index))
            if final is None or _key_after(transformer, language, anchor, text, final) != entry.key:
                stable.discard((entry.pair, entry.index))
        remaining = rest
    stable -= {(entry.pair, entry.index) for entry in remaining}  # rounds ran out before the site was checked
    return stable


def file_entries(
    transformer: StyleTransformer, language: str, anchor: str, code: str, stability: bool = True
) -> Entries:
    """The entries of one file version (cached per transformer); without `stability` every `stable` is False."""
    cache = _KEYS.get(transformer)
    if cache is None:
        cache = _KEYS[transformer] = OrderedDict()
    full = cache.get((anchor, code, True))
    if full is not None:
        cache.move_to_end((anchor, code, True))
        return full
    if not stability:
        cheap = cache.get((anchor, code, False))
        if cheap is None:
            cheap = cache[(anchor, code, False)] = _site_entries(transformer, language, anchor, code)
            if len(cache) > CACHE_SIZE:
                cache.popitem(last=False)
        return cheap
    cheap = file_entries(transformer, language, anchor, code, stability=False)
    stable = _stable(transformer, language, anchor, code, list(cheap))
    full = Entries(entry._replace(stable=(entry.pair, entry.index) in stable) for entry in cheap)
    full.errors = cheap.errors
    cache[(anchor, code, True)] = full
    if len(cache) > CACHE_SIZE:
        cache.popitem(last=False)
    return full


def select_entries(entries) -> list[Entry]:
    """The sites that carry votes: stable, usable, with windows that neither overlap nor touch, taken greedily in
    pre-order (outer node first, then pair order). Embedding and detection use the same selection."""
    regions = nodes._Regions()
    chosen = []
    ordered = sorted(
        (entry for entry in entries if entry.stable), key=lambda entry: (entry.site.start, -entry.site.end, entry.pair)
    )
    for entry in ordered:
        if regions.take(entry.site, (entry.pair, entry.index)):
            chosen.append(entry)
    return chosen


def observe_counted(
    transformer: StyleTransformer, language: str, files: Mapping[str, str], anchor: str, selected: bool = False
) -> tuple[list[Observation], int]:
    """`observe` and the number of (file, rule pair) combinations whose rules raised (they have no sites).

    With `selected`, only the sites of `select_entries` (the ones that carry votes) are returned.
    """
    observations = []
    errors = 0
    for name in project_order(files):
        entries = file_entries(transformer, language, anchor, files[name])
        errors += entries.errors
        for entry in select_entries(entries) if selected else entries:
            site = entry.site
            observations.append(
                Observation(
                    name, entry.pair, entry.index, site.reading, site.usable, entry.stable, site.window, entry.key
                )
            )
    return observations, errors


def observe(transformer: StyleTransformer, language: str, files: Mapping[str, str], anchor: str) -> list[Observation]:
    """Every site of the project with its anchor key and stability, in project file order, pair order, site order.

    A (file, rule pair) whose rules raise has no sites (counted by `observe_counted`, `EmbedResult.errors` and
    `Detection.errors`)."""
    return observe_counted(transformer, language, files, anchor)[0]

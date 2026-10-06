"""JavaScript rewrite rules, keyed by style id (see styles.json).

Families follow the C rules where JavaScript has the same construct (2.x operators,
3.x updates, 6.x declarations, 7.x loops, 14-19 control flow and member access); 23.x is
JavaScript-specific. Every rewrite is exact under JavaScript semantics:

* operand order only changes when the moved operands are literals or plain identifiers,
  so no getter, valueOf or call can observe a different evaluation order;
* negations wrap the whole test in !( ), which is the ToBoolean negation `if`/`?:` use;
* rules stay out of the operands of equality tests that the hash-order rules read;
* rewrites edit only the tokens that change (an operator, a keyword, an operand swapped in
  place), so whitespace and comments between them survive and the two directions of a pair
  stay exact inverses; layouts a direction would normalize are not candidates in either form.

Rules 20 and 24-29 follow the same scheme: a pair's candidate set must not change when the
other pairs are applied, so each rule also stays out of whatever the neighbouring rules read
(declaration adjacency, operand node types, member accesses, whether a statement exits).
"""

import hashlib
import re
from collections import OrderedDict

from .engine import (
    Edit,
    Matcher,
    Reject,
    delete_between,
    guard,
    insert_after,
    insert_before,
    replace,
    text,
    well_formed,
)


def nodes(node_type):
    return Matcher(f"(({node_type}) @node)")


def operator(node):
    return text(node.child_by_field_name("operator"))


EQUALITY = ["===", "==", "!==", "!="]
POSITIVE = {"===": "!==", "==": "!="}
NEGATIVE = {"!==": "===", "!=": "=="}
RELATIONAL = ["<", "<=", ">", ">="]
LITERALS = ["number", "string"]
SIMPLE = ["identifier", "number", "string", "true", "false", "null", "undefined"]
LOOSER_THAN_RELATIONAL = RELATIONAL + EQUALITY + ["&&", "||", "??", "&", "|", "^", "in", "instanceof"]
BINARY = nodes("binary_expression")


def is_equality(node):
    return node.type == "binary_expression" and operator(node) in EQUALITY


@guard("directly inside !(...)")
def negated(node):
    parent = node.parent
    return (
        parent is not None
        and parent.type == "parenthesized_expression"
        and len(parent.children) == 3
        and parent.parent is not None
        and parent.parent.type == "unary_expression"
        and operator(parent.parent) == "!"
    )


@guard("outside equality operands")
def outside_equality_operands(node):
    parent = node.parent
    while parent is not None and not parent.type.endswith(("statement", "declaration", "declarator")):
        if is_equality(parent):
            return False
        parent = parent.parent
    return True


def operator_in(*operators):
    return guard("operator " + "|".join(operators))(lambda node: operator(node) in operators)


# ---------------------------------------------------------------- file-level facts


def pattern_names(node):
    """Names bound (or, in an assignment target, written) by an identifier or destructuring pattern."""
    names, stack = set(), [node]
    while stack:
        current = stack.pop()
        if current is None:
            continue
        kind = current.type
        if kind in [
            "identifier",
            "shorthand_property_identifier_pattern",
            "undefined",
        ]:  # the grammar gives a binding named undefined its own node type
            names.add(text(current))
        elif kind in ["assignment_pattern", "object_assignment_pattern"]:
            stack.append(current.child_by_field_name("left"))
        elif kind == "pair_pattern":
            stack.append(current.child_by_field_name("value"))
        elif kind in [
            "array_pattern",
            "object_pattern",
            "rest_pattern",
            "formal_parameters",
            "parenthesized_expression",
        ]:
            stack.extend(current.children)
    return names


def root_name(node):
    """The variable at the base of an assignment target (`a` for `a.b[c]`), or None."""
    while node is not None and node.type in ["member_expression", "subscript_expression", "parenthesized_expression"]:
        node = node.child_by_field_name("object") if node.type != "parenthesized_expression" else node.children[1]
    return text(node) if node is not None and node.type == "identifier" else None


class Facts:
    """What the file-level guards need to know about a whole file, computed once per parse.

    names bound anywhere (by declaration, parameter, import, catch or loop head), const names, names
    declared by let/var/parameter, assignment targets with their positions (for scope queries), the
    base variables of all assignments, the names used by `a = a || b` / `a ||= b` shaped assignments,
    whether the file uses BigInt, and whether its scoping cannot be analysed: dynamic scoping (`with`, `eval`) or
    parse errors (the guards read declarations, and the parser may have misread them).

    The scope facts are collected on first use: the layout rules only read the source bytes. Only the nodes that
    `visit` acts on are visited, found by tree-sitter queries in C instead of a walk over every node in Python.
    """

    SCOPE = frozenset(["bound", "const", "mutable", "writes", "base_writes", "logical", "bigint", "opaque"])

    def __init__(self, root):
        self.root, self.data, self.base, self.root_column = root, root.text, root.start_byte, root.start_point[1]

    def __getattr__(self, name):
        # Called only while a scope fact is unset; afterwards they are plain attributes. The facts are collected on
        # a scratch object and published in one step, so a reader never sees half-collected sets.
        if name not in Facts.SCOPE:
            raise AttributeError(name)
        scratch = object.__new__(Facts)
        scratch.root, scratch.data = self.root, self.data
        scratch.bound, scratch.const, scratch.mutable = set(), set(), set()
        scratch.writes, scratch.base_writes, scratch.logical = [], set(), set()
        scratch.bigint = False
        scratch.opaque = self.root.has_error
        structure, identifiers = facts_queries()
        for node, _ in structure.captures(self.root):
            scratch.visit(node)
        if b"eval" in self.data or b"BigInt" in self.data:
            for node, _ in identifiers.captures(self.root):
                scratch.visit(node)
        self.__dict__.update({fact: scratch.__dict__[fact] for fact in Facts.SCOPE})
        return self.__dict__[name]

    def declare(self, names, kind):
        self.bound |= names
        if kind == "const":
            self.const |= names
        elif kind in ["let", "var"]:
            self.mutable |= names

    def visit(self, node):
        kind = node.type
        if kind == "variable_declarator":
            self.declare(pattern_names(node.child_by_field_name("name")), node.parent.children[0].type)
        elif kind in [
            "function_declaration",
            "generator_function_declaration",
            "class_declaration",
            "function",
            "generator_function",
            "class",
        ]:
            self.declare(pattern_names(node.child_by_field_name("name")), None)
        elif kind == "formal_parameters":
            self.declare(pattern_names(node), "let")
        elif kind == "arrow_function" and node.child_by_field_name("parameter") is not None:
            self.declare(pattern_names(node.child_by_field_name("parameter")), "let")
        elif kind == "catch_clause":
            self.declare(pattern_names(node.child_by_field_name("parameter")), None)
        elif kind == "import_statement":
            self.bound |= {text(child) for child in descendants(node) if child.type == "identifier"}
        elif kind == "for_in_statement":
            head = node.child_by_field_name("kind")
            if head is not None:
                self.declare(pattern_names(node.child_by_field_name("left")), head.type)
            else:
                self.write(node.child_by_field_name("left"))
        elif kind in ["assignment_expression", "augmented_assignment_expression"]:
            left = node.child_by_field_name("left")
            self.write(left)
            self.note_logical(node, left)
        elif kind == "update_expression":
            self.write(node.child_by_field_name("argument"))
        elif kind == "with_statement" or (kind == "identifier" and node.text == b"eval"):
            self.opaque = True
        elif kind == "number":
            self.bigint = self.bigint or node.text.endswith(b"n")
        elif kind == "identifier" and node.text.startswith(b"BigInt"):
            self.bigint = True

    def write(self, target):
        if target is None:
            return
        base = root_name(target)
        if base is not None:
            self.base_writes.add(base)
        names = pattern_names(target)
        if names:
            self.writes.append((target.start_byte, names))
            self.base_writes |= names

    def note_logical(self, node, left):
        """Names of `a = a || b`, `a = a && b`, `a = a ?? b` and `a ||= b`, `a &&= b`, `a ??= b` (whatever b is)."""
        if left.type != "identifier":
            return
        if node.type == "augmented_assignment_expression":
            if operator(node) in ["||=", "&&=", "??="]:
                self.logical.add(text(left))
            return
        value = node.child_by_field_name("right")
        if (
            value.type == "binary_expression"
            and operator(value) in ["||", "&&", "??"]
            and text(value.child_by_field_name("left")) == text(left)
        ):
            self.logical.add(text(left))

    def bytes(self, start, end):
        """The source between two byte offsets (offsets as reported by nodes)."""
        return self.data[start - self.base : end - self.base]

    def written_in(self, scope):
        """Names assigned somewhere inside `scope` (by name only: shadowing is not analysed)."""
        names = set()
        for position, written in self.writes:
            if scope.start_byte <= position < scope.end_byte:
                names |= written
        return names


# Every node `Facts.visit` acts on: the structural nodes and numbers, and the identifiers, which are queried only
# when the file contains the bytes of `eval` or `BigInt` (the only identifiers `visit` reacts to). Each node is
# captured at most once, and the facts are sets (`writes` is only read as a union), so the order of the captures does
# not matter. Anonymous `function`/`class` keywords are not captured; `visit` finds no name under them. Text
# predicates are left out: py-tree-sitter evaluates them in Python, after a full match.
FACT_PATTERNS = """
[(variable_declarator) (function_declaration) (generator_function_declaration) (class_declaration) (function)
 (generator_function) (class) (formal_parameters) (arrow_function) (catch_clause) (import_statement)
 (for_in_statement) (assignment_expression) (augmented_assignment_expression) (update_expression)
 (with_statement) (number)] @fact
"""
_FACT_QUERIES = {}


def facts_queries():
    """(structure query, identifier query) for the grammar that `cllmark.transform` loads, compiled once per library."""
    from ..transform import library_path, load_grammar

    library = library_path("javascript")
    queries = _FACT_QUERIES.get(library)
    if queries is None:
        language = load_grammar(library, "javascript").language
        queries = _FACT_QUERIES[library] = (language.query(FACT_PATTERNS), language.query("(identifier) @fact"))
    return queries


def descendants(node):
    stack = list(node.children)
    while stack:
        current = stack.pop()
        yield current
        stack.extend(current.children)


_FACTS = OrderedDict()


def file_facts(node):
    """Facts of the file containing `node`. The cache holds the root node (and so its tree), which keeps ids unique."""
    root = node
    while root.parent is not None:
        root = root.parent
    facts = _FACTS.get(root.id)
    if facts is None:
        facts = _FACTS[root.id] = Facts(root)
        if len(_FACTS) > 12:
            _FACTS.popitem(last=False)
    else:
        _FACTS.move_to_end(root.id)
    return facts


def leading_whitespace(facts, node):
    """The whitespace before `node` on its line, or None when other text precedes it."""
    start = node.start_byte - facts.base
    line = facts.data.rfind(b"\n", 0, start) + 1
    if line == 0 and facts.root_column > 0:
        return None  # the root node starts after indentation that its text does not contain
    prefix = facts.data[line:start]
    return prefix if not prefix.strip(b" \t") else None


# ---------------------------------------------------------------- 2.x equality, relational and assignment


def negate_equality(node, source):
    """a === b -> !(a !== b)   (only the operator changes; the operands keep their spacing and comments)"""
    flipped = POSITIVE.get(operator(node)) or NEGATIVE[operator(node)]
    return [insert_before(node, "!("), replace(node.child_by_field_name("operator"), flipped), insert_after(node, ")")]


# Operators that bind tighter than == / ===: without the parentheses of !( ) they would capture only
# part of the unwrapped comparison.
LOOSER_THAN_EQUALITY = ["&&", "||", "??", "&", "|", "^"]


def bare_comparison_allowed(node):
    """Whether `!(a != b)` may be written `a == b` at this place."""
    parent = node.parent
    if parent.type in ["unary_expression", "await_expression", "update_expression"]:
        return False
    return not (parent.type == "binary_expression" and operator(parent) not in LOOSER_THAN_EQUALITY)


def negated_test(operators):
    """!(a <op> b), written exactly like that and standing where the bare comparison parses the same"""

    def test(node):
        if operator(node) != "!":
            return False
        group = node.child_by_field_name("argument")
        if (
            group.type != "parenthesized_expression"
            or len(group.children) != 3
            or group.children[1].type != "binary_expression"
            or operator(group.children[1]) not in operators
        ):
            return False
        inner = group.children[1]
        prefix, suffix = inner.start_byte - node.start_byte, node.end_byte - inner.end_byte
        return (
            node.text[:prefix] == b"!("
            and node.text[len(node.text) - suffix :] == b")"
            and bare_comparison_allowed(node)
        )

    return nodes("unary_expression").where(guard("!(a " + "|".join(operators) + " b)")(test))


def remove_negation(node, source):
    """!(a !== b) -> a === b"""
    inner = node.child_by_field_name("argument").children[1]
    flipped = POSITIVE.get(operator(inner)) or NEGATIVE[operator(inner)]
    return [
        delete_between(node.start_byte, inner.start_byte),
        replace(inner.child_by_field_name("operator"), flipped),
        delete_between(inner.end_byte, node.end_byte),
    ]


MIRROR = {"<": ">", "<=": ">=", ">": "<", ">=": "<="}


def literal_comparison(literal_on_left):
    """A relational test with exactly one literal operand, on the given side."""

    def test(node):
        left, right = node.child_by_field_name("left"), node.child_by_field_name("right")
        if any(side.type == "binary_expression" and operator(side) in LOOSER_THAN_RELATIONAL for side in [left, right]):
            return False
        literal, other = (left, right) if literal_on_left else (right, left)
        return literal.type in LITERALS and other.type not in LITERALS

    return BINARY.where(
        operator_in(*RELATIONAL), guard("literal on the " + ("left" if literal_on_left else "right"))(test)
    )


WORD = re.compile(rb"[A-Za-z0-9_$]")
SIGN = b"+-*/%&|^<>=!?:.~"


def fuses(before, after, new):
    """Whether text `new` standing between the bytes `before` and `after` would merge with them into other tokens
    (minified code writes `return"a"===x`; swapping the operands must not give `returnx==="a"` or `a+ +b`)."""

    def joins(left, right):
        return bool(left and right) and (
            bool(WORD.match(left) and WORD.match(right)) or (left in SIGN and right in SIGN)
        )

    return joins(before, new[:1]) or joins(new[-1:], after)


HTML_COMMENT_TOKENS = [b"<!--", b"-->"]


def swap_operands(source, left, right, operator_edit=None):
    """Edits that trade the two operands in place (and optionally replace the operator between them), or Reject
    when the new text would fuse with its surroundings or spell an HTML-like comment token."""
    operator_node, operator_text = operator_edit or (None, None)
    old = source.data[left.start_byte : right.end_byte]
    middle = source.data[left.end_byte : right.start_byte]
    if operator_node is not None:
        middle = (
            source.data[left.end_byte : operator_node.start_byte]
            + operator_text.encode()
            + source.data[operator_node.end_byte : right.start_byte]
        )
    new = right.text + middle + left.text
    if (
        fuses(source.data[left.start_byte - 1 : left.start_byte], b"", right.text)
        or fuses(b"", source.data[right.end_byte : right.end_byte + 1], left.text)
        or any(token in new and token not in old for token in HTML_COMMENT_TOKENS)
    ):
        raise Reject("the swapped operands would fuse with their surroundings")
    edits = [replace(left, text(right)), replace(right, text(left))]
    return edits if operator_node is None else [edits[0], replace(operator_node, operator_text), edits[1]]


def mirror(node, source):
    """x > 0 -> 0 < x (the literal has no side effects, so evaluation order is unobservable)"""
    operator_node = node.child_by_field_name("operator")
    return swap_operands(
        source,
        node.child_by_field_name("left"),
        node.child_by_field_name("right"),
        (operator_node, MIRROR[operator(node)]),
    )


def hash_at_least(left, right):
    return int(hashlib.sha256(left.encode("utf-8")).hexdigest(), 16) >= int(
        hashlib.sha256(right.encode("utf-8")).hexdigest(), 16
    )


def hash_order(equality_rule, swap_when_left_hash_larger):
    """a === b -> b === a following the operands' SHA-256 order (equality is symmetric).

    As in the C and Python rules, the equality rule owns === / == outside !( ) and
    !== / != inside it; the inequality rule owns the other two cases.
    """

    def rewrite(node, source):
        positive = operator(node) in POSITIVE
        if (positive != negated(node)) != equality_rule:
            raise Reject("other operator")
        left_node, right_node = node.child_by_field_name("left"), node.child_by_field_name("right")
        left, right = text(left_node), text(right_node)
        if hash_at_least(left, right) != swap_when_left_hash_larger:
            raise Reject("already in order")
        return swap_operands(source, left_node, right_node)

    return rewrite


SIMPLE_EQUALITY = BINARY.where(
    operator_in(*EQUALITY),
    guard("identifier/literal operands")(
        lambda node: (
            node.child_by_field_name("left").type in SIMPLE and node.child_by_field_name("right").type in SIMPLE
        )
    ),
)
COMPOUND = ["+", "-", "*", "/", "%", "**", "<<", ">>", ">>>", "&", "|", "^"]
OPERAND = [
    *SIMPLE,
    "member_expression",
    "subscript_expression",
    "call_expression",
    "parenthesized_expression",
    "unary_expression",
]


def negated_comparison(node):
    """!(a === b): what the equality rules write, whereas the bare comparison is not a plain operand."""
    if node.type != "unary_expression" or operator(node) != "!":
        return False
    group = node.child_by_field_name("argument")
    return group.type == "parenthesized_expression" and len(group.children) == 3 and is_equality(group.children[1])


def plain_operand(node):
    """An operand the assignment rules accept: one that needs no parentheses next to an operator and that the
    equality rules neither create (`!(a === b)` from `a !== b`) nor remove."""
    return node.type in OPERAND and not negated_comparison(node)


@guard("x = x <op> y, spelled so, with a plain y")
def self_assignment(node):
    target, value = node.child_by_field_name("left"), node.child_by_field_name("right")
    return (
        target.type == "identifier"
        and value.type == "binary_expression"
        and operator(value) in COMPOUND
        and text(value.child_by_field_name("left")) == text(target)
        and plain_operand(value.child_by_field_name("right"))
        and node.text
        == f"{text(target)} = {text(target)} {operator(value)} ".encode() + value.child_by_field_name("right").text
    )


@guard("x <op>= y, spelled so, with a plain y")
def compound_assignment(node):
    target, value = node.child_by_field_name("left"), node.child_by_field_name("right")
    return (
        target.type == "identifier"
        and operator(node)[:-1] in COMPOUND
        and plain_operand(value)
        and node.text == f"{text(target)} {operator(node)} ".encode() + value.text
    )


def to_compound(node, source):
    """x = x + y -> x += y"""
    value = node.child_by_field_name("right")
    return [
        Edit(
            node.start_byte,
            value.child_by_field_name("right").start_byte,
            f"{text(node.child_by_field_name('left'))} {operator(value)}= ",
        )
    ]


def from_compound(node, source):
    """x += y -> x = x + y"""
    target = text(node.child_by_field_name("left"))
    return [
        Edit(
            node.start_byte, node.child_by_field_name("right").start_byte, f"{target} = {target} {operator(node)[:-1]} "
        )
    ]


# ---------------------------------------------------------------- 3.x ++ / --


@guard("value unused (statement or for-update, not the test of a for)")
def value_unused(node):
    parent = node.parent
    if parent.type == "expression_statement":
        # `for (; i--; )` holds its test in an expression statement, and the loop-form rule produces it from `while (i--)`
        return not (parent.parent.type == "for_statement" and parent.parent.child_by_field_name("condition") == parent)
    return parent.type == "for_statement" and parent.child_by_field_name("increment") == node


def prefix_form(prefix):
    return guard("prefix ++/--" if prefix else "postfix ++/--")(
        lambda node: node.children[0].type in ["++", "--"] if prefix else node.children[1].type in ["++", "--"]
    )


@guard("operator and operand on one line")
def one_line_update(node):
    """`i\\n++` is not a postfix update (ASI), so a line break must never be moved across the operator."""
    return node.start_point[0] == node.end_point[0]


def flip_update(node, source):
    """i++ -> ++i (and back; the operator and the operand trade places, the space between them stays)"""
    first, second = node.children
    return [replace(first, text(second)), replace(second, text(first))]


# ---------------------------------------------------------------- 6.x declarations

DECLARATIONS = ["lexical_declaration", "variable_declaration"]


def keyword(declaration):
    return text(declaration.children[0])


def declarators(declaration):
    return [child for child in declaration.children if child.type == "variable_declarator"]


def cluster_member(node):
    """A declaration in canonical layout: `kind a = 1, b = 2;` on one line, directly in a block."""
    if (
        node is None
        or node.type not in DECLARATIONS
        or node.parent.type not in ["program", "statement_block"]
        or node.children[-1].type != ";"
        or node.start_point[0] != node.end_point[0]
    ):
        return False
    items = declarators(node)
    return bool(items) and node.text == (keyword(node) + " " + ", ".join(text(item) for item in items) + ";").encode()


def adjacent_members(facts, previous, node):
    """`previous` and `node` are consecutive declarations of one keyword on consecutive lines at one indentation."""
    indent = leading_whitespace(facts, node)
    return (
        cluster_member(previous)
        and cluster_member(node)
        and keyword(previous) == keyword(node)
        and indent is not None
        and leading_whitespace(facts, previous) == indent
        and facts.bytes(previous.end_byte, node.start_byte) == b"\n" + indent
    )


def declaration_cluster(node):
    """The run of declarations adjacent to each other that starts at `node`; empty when `node` does not start one.

    Both directions of the pair work on whole clusters: splitting turns every multi-name declaration of the
    cluster into single-name ones, merging joins all of them into one. Each result still is one cluster, so the
    two directions are exact inverses and neither changes which declarations the other sees.
    """
    facts = file_facts(node)
    if not cluster_member(node) or leading_whitespace(facts, node) is None:
        return []
    if adjacent_members(facts, node.prev_sibling, node):
        return []
    run, following = [node], node.next_sibling
    while following is not None and adjacent_members(facts, run[-1], following):
        run.append(following)
        following = following.next_sibling
    return run


@guard("first declaration of a cluster that has a multi-name declaration")
def splittable_cluster(node):
    return any(len(declarators(item)) > 1 for item in declaration_cluster(node))


@guard("first declaration of a cluster of two or more declarations")
def mergeable_cluster(node):
    return len(declaration_cluster(node)) > 1


def split_declaration(node, source):
    """let a = 1, b = 2; -> let a = 1; / let b = 2;"""
    indent = leading_whitespace(file_facts(node), node).decode()
    return [
        replace(item, f"\n{indent}".join(f"{keyword(item)} {text(part)};" for part in declarators(item)))
        for item in declaration_cluster(node)
        if len(declarators(item)) > 1
    ]


def merge_declarations(node, source):
    """let a = 1; / let b = 2; -> let a = 1, b = 2;"""
    run = declaration_cluster(node)
    merged = f"{keyword(node)} " + ", ".join(text(part) for item in run for part in declarators(item)) + ";"
    return [Edit(node.start_byte, run[-1].end_byte, merged)]


# ---------------------------------------------------------------- 7.x while / for(;;)


def header(node):
    """Source text from the statement start to its body: `while (c) ` or `for (; c; ) `."""
    return node.text[: node.child_by_field_name("body").start_byte - node.start_byte]


@guard("for (; c; ) S without init or update, spaced exactly like that")
def condition_only_for(node):
    if (
        node.child_by_field_name("increment") is not None
        or node.children[2].type != "empty_statement"
        or node.children[3].type != "expression_statement"
        or node.children[3].children[-1].type != ";"
    ):
        return False
    condition = node.children[3].children[0]
    return condition.type != "sequence_expression" and header(node) == f"for (; {text(condition)}; ) ".encode()


@guard("while (c) S, spaced exactly like that")
def plain_while(node):
    condition = node.child_by_field_name("condition")
    return (
        len(condition.children) == 3
        and condition.children[1].type != "sequence_expression"
        and header(node) == b"while " + condition.text + b" "
        and condition.text == b"(" + condition.children[1].text + b")"
    )


def for_to_while(node, source):
    """for (; c; ) S -> while (c) S"""
    condition = node.children[3].children[0]
    return [Edit(node.start_byte, node.child_by_field_name("body").start_byte, f"while ({text(condition)}) ")]


def while_to_for(node, source):
    """while (c) S -> for (; c; ) S"""
    condition = node.child_by_field_name("condition")
    return [
        Edit(node.start_byte, node.child_by_field_name("body").start_byte, f"for (; {text(condition.children[1])}; ) ")
    ]


# ---------------------------------------------------------------- 14-16 branches and conditions


def negated_group(node):
    return (
        node.type == "unary_expression"
        and operator(node) == "!"
        and node.child_by_field_name("argument").type == "parenthesized_expression"
        and len(node.child_by_field_name("argument").children) == 3
    )


def negatable(expression):
    return (
        not is_equality(expression)
        and not negated_group(expression)
        and expression.type not in ["sequence_expression", "assignment_expression", "augmented_assignment_expression"]
    )


def statements(block):
    return [child for child in block.children[1:-1] if child.type != "comment"]


def closed_block(block):
    """A block that ends with its own `}`. The parser attaches a comment that follows `}` on the same line to the
    block (`} // note`), and text moved or extended at the block's end would then land inside that comment."""
    return block.type == "statement_block" and block.children[-1].type == "}"


def condition_value(statement):
    group = statement.child_by_field_name("condition")
    return group.children[1] if group is not None and len(group.children) == 3 else None


def contains(node, predicate):
    stack = list(node.children)
    while stack:
        current = stack.pop()
        if predicate(current):
            return True
        stack.extend(current.children)
    return False


def has_else(node):
    return node.type == "if_statement" and node.child_by_field_name("alternative") is not None


EXITS = ["return_statement", "throw_statement"]


def exits(block):
    """The block always leaves the function: it ends with return/throw, or with an if/else whose branches
    all exit (so both forms of the else-after-return rule count)."""
    items = statements(block) if block.type == "statement_block" else [block]
    if not items:
        return False
    last = items[-1]
    if last.type in EXITS:
        return True
    if last.type == "statement_block":
        return exits(last)
    if last.type != "if_statement" or last.child_by_field_name("alternative") is None:
        return False
    alternative = [child for child in last.child_by_field_name("alternative").children if child.is_named]
    return exits(last.child_by_field_name("consequence")) and len(alternative) == 1 and exits(alternative[0])


def exiting_if(node):
    consequence = node.child_by_field_name("consequence") if node.type == "if_statement" else None
    return consequence is not None and consequence.type == "statement_block" and exits(consequence)


def nested_branching(node):
    """An if/else, or an exiting if that the else-after-return rule may give an else."""
    return has_else(node) or exiting_if(node)


def braced_if_else(negated_form):
    """if (c) { A } else { B } (or the !(c) form) with two non-exiting blocks; blocks holding another
    if/else or exiting if are left alone so that nested candidates never overlap or change status."""

    def test(node):
        value, clause = condition_value(node), node.child_by_field_name("alternative")
        consequence = node.child_by_field_name("consequence")
        if value is None or clause is None or consequence.type != "statement_block":
            return False
        branch = [child for child in clause.children if child.is_named]
        if (
            len(branch) != 1
            or not closed_block(branch[0])
            or not closed_block(consequence)
            or exits(consequence)
            or exits(branch[0])
            or contains(consequence, nested_branching)
            or contains(branch[0], nested_branching)
        ):
            return False
        return (
            negated_group(value) and negatable(value.child_by_field_name("argument").children[1])
            if negated_form
            else negatable(value)
        )

    return nodes("if_statement").where(
        guard("if (!(c)) {..} else {..}" if negated_form else "if (c) {..} else {..}")(test)
    )


def swap_branches(negate):
    """if (c) { A } else { B } -> if (!(c)) { B } else { A }   (and back)"""

    def rewrite(node, source):
        value = condition_value(node)
        consequence = node.child_by_field_name("consequence")
        alternative = [child for child in node.child_by_field_name("alternative").children if child.is_named][0]
        flipped = f"!({text(value)})" if negate else text(value.child_by_field_name("argument").children[1])
        return [
            replace(value, flipped),
            replace(consequence, text(alternative)),
            replace(alternative, text(consequence)),
        ]

    return rewrite


def movable_conditional(negated_form):
    def test(node):
        condition = node.child_by_field_name("condition")
        if any(
            node.child_by_field_name(field).type == "sequence_expression" for field in ["consequence", "alternative"]
        ):
            return False
        if contains(node, lambda child: child.type == "ternary_expression"):
            return False
        return (
            negated_group(condition) and negatable(condition.child_by_field_name("argument").children[1])
            if negated_form
            else negatable(condition)
        )

    return nodes("ternary_expression").where(
        guard("!(c) ? a : b" if negated_form else "c ? a : b")(test), outside_equality_operands
    )


def swap_conditional(negate):
    """c ? a : b -> !(c) ? b : a   (and back; the operands trade places, layout kept)"""

    def rewrite(node, source):
        condition = node.child_by_field_name("condition")
        a, b = node.child_by_field_name("consequence"), node.child_by_field_name("alternative")
        flipped = f"!({text(condition)})" if negate else text(condition.child_by_field_name("argument").children[1])
        return [replace(condition, flipped), replace(a, text(b)), replace(b, text(a))]

    return rewrite


def conjunct(node):
    return node.type not in [
        "sequence_expression",
        "assignment_expression",
        "augmented_assignment_expression",
        "ternary_expression",
        "arrow_function",
        "yield_expression",
    ] and not (node.type == "binary_expression" and operator(node) in ["&&", "||", "??"])


@guard("if (a && b) { S } without else")
def conjunctive_if(node):
    value, consequence = condition_value(node), node.child_by_field_name("consequence")
    if (
        value is None
        or node.child_by_field_name("alternative") is not None
        or consequence.type != "statement_block"
        or exits(consequence)
    ):
        return False
    left, right = value.child_by_field_name("left"), value.child_by_field_name("right")
    return (
        value.type == "binary_expression"
        and operator(value) == "&&"
        and conjunct(left)
        and conjunct(right)
        and value.text[left.end_byte - value.start_byte : right.start_byte - value.start_byte] == b" && "
    )


@guard("if (a) if (b) { S } without else")
def nested_if(node):
    consequence = node.child_by_field_name("consequence")
    if (
        condition_value(node) is None
        or node.child_by_field_name("alternative") is not None
        or consequence.type != "if_statement"
        or consequence.child_by_field_name("alternative") is not None
    ):
        return False
    body = consequence.child_by_field_name("consequence")
    inner, outer = condition_value(consequence), condition_value(node)
    return (
        inner is not None
        and body.type == "statement_block"
        and not exits(body)
        and conjunct(outer)
        and conjunct(inner)
        and node.text[outer.end_byte - node.start_byte : inner.start_byte - node.start_byte] == b") if ("
    )


def split_conjunction(node, source):
    """if (a && b) { S } -> if (a) if (b) { S }"""
    value = condition_value(node)
    return [Edit(value.child_by_field_name("left").end_byte, value.child_by_field_name("right").start_byte, ") if (")]


def join_conjunction(node, source):
    """if (a) if (b) { S } -> if (a && b) { S }"""
    return [
        Edit(
            condition_value(node).end_byte, condition_value(node.child_by_field_name("consequence")).start_byte, " && "
        )
    ]


# ---------------------------------------------------------------- 18 final return in functions

FUNCTIONS = "[(function_declaration) (function) (generator_function_declaration) (generator_function) (method_definition) (arrow_function)] @node"


def function_body(node):
    body = node.child_by_field_name("body")
    return body if body is not None and body.type == "statement_block" else None


def blank_between(node, first, second):
    """Only whitespace separates the two nodes (no comment that would change sides when a statement is added or dropped)."""
    return not file_facts(node).bytes(first.end_byte, second.start_byte).strip()


@guard("function body ending with return; (and no comment around it)")
def ends_with_bare_return(node):
    body = function_body(node)
    items = statements(body) if body else []
    return (
        len(items) >= 2
        and closed_block(body)
        and items[-1].type == "return_statement"
        and [child.type for child in items[-1].children] == ["return", ";"]
        and blank_between(node, items[-2], items[-1])
        and blank_between(node, items[-1], body.children[-1])
    )


@guard("non-empty function body without a final return (and no comment after the last statement)")
def ends_without_return(node):
    body = function_body(node)
    items = statements(body) if body else []
    return (
        bool(items)
        and closed_block(body)
        and items[-1].type != "return_statement"
        and blank_between(node, items[-1], body.children[-1])
    )


def add_final_return(node, source):
    """function f() { ...; } -> function f() { ...; return; }"""
    last = statements(function_body(node))[-1]
    indent = source.leading(last)
    if indent is None:
        raise Reject("last statement shares its line")
    return [insert_after(last, f"\n{indent}return;")]


def drop_final_return(node, source):
    """function f() { ...; return; } -> function f() { ...; }"""
    final = statements(function_body(node))[-1]
    return [delete_between(final.prev_sibling.end_byte, final.end_byte)]


# ---------------------------------------------------------------- 19 member access

IDENTIFIER_NAME = re.compile(r"^[A-Za-z_$][A-Za-z0-9_$]*$")
# Accesses that the global-alias (28) and power (27) rules create or consume: keeping them out of this
# pair keeps the candidates of both pairs independent of each other.
ALIAS_ACCESSES = {("Number", "parseInt"), ("Number", "parseFloat"), ("Math", "pow")}


def alias_access(node, name):
    obj = node.child_by_field_name("object")
    return obj is not None and obj.type == "identifier" and (text(obj), name) in ALIAS_ACCESSES


@guard("o.name written without space (no optional chaining or private name, not on a number)")
def dot_access(node):
    field = node.child_by_field_name("property")
    dots = [child for child in node.children if child.type == "."]
    return (
        field is not None
        and field.type == "property_identifier"
        and not any(child.type == "optional_chain" for child in node.children)
        and len(dots) == 1
        and node.text[dots[0].start_byte - node.start_byte :] == b"." + field.text
        and node.child_by_field_name("object").type != "number"
        and not alias_access(node, text(field))
    )


@guard('o["name"] written without space or comments, with an identifier-like double-quoted name (not on a number)')
def bracket_access(node):
    index = node.child_by_field_name("index")
    brackets = [child for child in node.children if child.type == "["]
    return (
        index is not None
        and index.type == "string"
        and len(index.children) == 3
        and text(index)[0] == '"'
        and IDENTIFIER_NAME.match(text(index)[1:-1]) is not None
        and not any(child.type == "optional_chain" for child in node.children)
        and len(brackets) == 1
        and node.text[brackets[0].start_byte - node.start_byte :] == b"[" + index.text + b"]"
        and node.child_by_field_name("object").type != "number"
        and not alias_access(node, text(index)[1:-1])
    )


def to_bracket(node, source):
    """o.name -> o["name"]  (only the accessor changes, so accesses nested in o are independent edits
    and a line break or comment between o and the dot stays where it is)"""
    dot = [child for child in node.children if child.type == "."][0]
    return [Edit(dot.start_byte, node.end_byte, f'["{text(node.child_by_field_name("property"))}"]')]


def to_dot(node, source):
    """o["name"] -> o.name"""
    bracket = [child for child in node.children if child.type == "["][0]
    return [Edit(bracket.start_byte, node.end_byte, "." + text(node.child_by_field_name("index"))[1:-1])]


# ---------------------------------------------------------------- 20 else after return

BLOCK_SCOPED = ["lexical_declaration", "class_declaration", "function_declaration", "generator_function_declaration"]


def bare_exiting_if(node):
    return exiting_if(node) and node.child_by_field_name("alternative") is None


def exiting_if_else(node):
    clause = node.child_by_field_name("alternative") if exiting_if(node) else None
    return clause is not None and len(clause.children) == 2 and clause.children[1].type == "statement_block"


def holds_exiting_if(items):
    return any(exiting_if(item) or contains(item, exiting_if) for item in items)


def raw_text_free(node):
    """Moving statements one level re-indents their lines: leave text whose lines are content alone."""
    return b"\\\n" not in node.text and not contains(
        node, lambda child: child.type.startswith("jsx") or (child.type == "template_string" and b"\n" in child.text)
    )


def block_scoped_free(items):
    return not any(item.type in BLOCK_SCOPED for item in items)


def function_level(block):
    """The block is the body of a function. Void-return (18) adds or drops the final `return;` of exactly such
    blocks, and what it sees there (a last statement that is or is not a return) changes when an else is added
    or removed, so function bodies are left to that rule (the C rule leaves out void function bodies for the same reason)."""
    return block.parent is not None and block.parent.type in [
        "function_declaration",
        "function",
        "generator_function_declaration",
        "generator_function",
        "method_definition",
        "arrow_function",
    ]


@guard(
    "the only exiting if of a block outside function bodies, last in it, with an else-block free of exiting ifs and block-scoped declarations"
)
def exiting_braced_if_else(node):
    if (
        not exiting_if_else(node)
        or node.parent.type != "statement_block"
        or node.parent.children[-2] != node
        or function_level(node.parent)
    ):
        return False
    block = node.child_by_field_name("alternative").children[1]
    body = statements(block)
    return (
        bool(body)
        and closed_block(block)
        and closed_block(node.child_by_field_name("consequence"))
        and block_scoped_free(body)
        and raw_text_free(block)
        and not any(bare_exiting_if(item) for item in statements(node.parent))
        and not holds_exiting_if(body)
    )


def trailing_statements(node):
    following, rest = node.next_sibling, []
    while following is not None and following.type != "}":
        rest.append(following)
        following = following.next_sibling
    return rest


@guard(
    "the only exiting if of a block outside function bodies, followed by the rest of the block (free of exiting ifs and block-scoped declarations)"
)
def exiting_braced_if_then_rest(node):
    if (
        not bare_exiting_if(node)
        or node.parent.type != "statement_block"
        or function_level(node.parent)
        or not closed_block(node.child_by_field_name("consequence"))
    ):
        return False
    rest = [item for item in trailing_statements(node) if item.type != "comment"]
    return (
        bool(rest)
        and sum(bare_exiting_if(item) for item in statements(node.parent)) == 1
        and not holds_exiting_if(rest)
        and block_scoped_free(rest)
        and all(raw_text_free(item) for item in rest)
    )


def reindent(source, start, end, old, new):
    lines = source.data[start:end].decode("utf-8").split("\n")
    return "\n".join(lines[:1] + [new + line[len(old) :] if line.startswith(old) else line for line in lines[1:]])


def drop_braced_else(node, source):
    """if (c) { ...return x; } else { B } -> if (c) { ...return x; } B   (B moved out one level)"""
    clause = node.child_by_field_name("alternative")
    block = clause.children[1]
    inner = statements(block)
    outer, nested = source.leading(node), source.leading(inner[0])
    consequence = node.child_by_field_name("consequence")
    if (
        outer is None
        or nested is None
        or source.data[consequence.end_byte : block.children[1].start_byte] != f" else {{\n{nested}".encode()
        or source.data[block.children[-2].end_byte : block.end_byte] != f"\n{outer}}}".encode()
    ):
        raise Reject('not the canonical "} else {" layout')
    moved = reindent(source, block.children[1].start_byte, block.children[-2].end_byte, nested, outer)
    return [Edit(consequence.end_byte, clause.end_byte, f"\n{outer}{moved}")]


def add_braced_else(node, source):
    """if (c) { ...return x; } B -> if (c) { ...return x; } else { B }"""
    consequence = node.child_by_field_name("consequence")
    rest = trailing_statements(node)
    outer, nested = source.leading(node), source.leading(statements(consequence)[0])
    if (
        outer is None
        or nested is None
        or source.data[consequence.end_byte : rest[0].start_byte] != ("\n" + outer).encode()
    ):
        raise Reject("irregular layout")
    moved = reindent(source, rest[0].start_byte, rest[-1].end_byte, outer, nested)
    return [Edit(consequence.end_byte, rest[-1].end_byte, f" else {{\n{nested}{moved}\n{outer}}}")]


# ---------------------------------------------------------------- 23 property shorthand


@guard("{ a: a } with a plain identifier key and value, spelled so")
def explicit_property(node):
    key, value = node.child_by_field_name("key"), node.child_by_field_name("value")
    return (
        node.parent.type == "object"
        and key.type == "property_identifier"
        and value.type == "identifier"
        and text(key) == text(value)
        and text(key) not in ["__proto__", "undefined"]
        and node.text == key.text + b": " + value.text
    )


@guard("{ a } in an object literal")
def shorthand_property(node):
    return node.parent.type == "object" and text(node) not in ["__proto__", "undefined"]


# ---------------------------------------------------------------- 24 arrow function body

CLOSING = re.compile(rb"(?:\s|//[^\n]*|/\*.*?\*/)*", re.S)
CONTINUING_WORDS = [b"in", b"instanceof", b"of"]


def arrow_closed(node):
    """What follows the arrow can neither continue a concise body (`x => a` + newline + `(b)` would call a)
    nor be told apart by it: a closing token, a new statement on the next line, or the end of the file."""
    facts = file_facts(node)
    end = node.end_byte - facts.base
    position = CLOSING.match(facts.data, end).end()
    following = facts.data[position : position + 1]
    if not following or following in b";,)]}:":
        return True
    word = re.match(rb"[A-Za-z_$][A-Za-z0-9_$]*", facts.data[position:])
    return word is not None and b"\n" in facts.data[end:position] and word.group() not in CONTINUING_WORDS


def in_for_initializer(node):
    parent = node.parent
    while parent is not None:
        if parent.type == "for_statement":
            initializer = parent.child_by_field_name("initializer")
            if (
                initializer is not None
                and initializer.start_byte <= node.start_byte
                and node.end_byte <= initializer.end_byte
            ):
                return True
        parent = parent.parent
    return False


@guard("arrow function outside comparisons and for initialisers, closed by the next token")
def arrow_site(node):
    return outside_equality_operands(node) and not in_for_initializer(node) and arrow_closed(node)


def block_end(body):
    """The closing `}` of a block body (a comment after it on the same line belongs to the parsed block, not to the code)."""
    return body.children[-1] if closed_block(body) else [child for child in body.children if child.type == "}"][-1]


def returned(body):
    """The `e` of a block body written exactly `{ return e; }`, else None."""
    if (
        body.type != "statement_block"
        or len(body.children) < 3
        or body.children[1].type != "return_statement"
        or [child.type for child in body.children[2:]].count("}") != 1
    ):
        return None
    statement, close = body.children[1], block_end(body)
    if body.children[2] != close or len(statement.children) != 3 or statement.children[2].type != ";":
        return None
    value = statement.children[1]
    written = file_facts(body).bytes(body.start_byte, close.end_byte)
    return value if written == b"{ return " + value.text + b"; }" else None


def ends_with_comment(node):
    while node.children:
        node = node.children[-1]
    return node.type == "comment"


@guard("arrow function with an expression body")
def concise_arrow(node):
    body = node.child_by_field_name("body")
    return body.type != "statement_block" and not ends_with_comment(body) and arrow_site(node)


@guard("arrow function whose block body is exactly { return e; } with an e that can stand alone as a body")
def returning_arrow(node):
    value = returned(node.child_by_field_name("body"))
    return (
        value is not None
        and value.type != "sequence_expression"
        and not value.text.startswith(b"{")
        and arrow_site(node)
    )


def to_block_body(node, source):
    """x => e  ->  x => { return e; }   (an object literal or sequence keeps the parentheses it already has)"""
    body = node.child_by_field_name("body")
    return [insert_before(body, "{ return "), insert_after(body, "; }")]


def to_expression_body(node, source):
    """x => { return e; }  ->  x => e"""
    body = node.child_by_field_name("body")
    value = returned(body)
    return [delete_between(body.start_byte, value.start_byte), delete_between(value.end_byte, block_end(body).end_byte)]


# ---------------------------------------------------------------- 25 const / let

SCOPE_PARENTS = ["program", "statement_block", "switch_case", "switch_default"]


def declared_neighbour(node):
    for step in ["prev_sibling", "next_sibling"]:
        neighbour = getattr(node, step)
        while neighbour is not None and neighbour.type == "comment":
            neighbour = getattr(neighbour, step)
        if neighbour is not None and neighbour.type in DECLARATIONS:
            return True
    return False


def never_written(current):
    """A single initialised name declared with `current` that no assignment in its scope writes."""

    def test(node):
        if keyword(node) != current or node.parent.type not in SCOPE_PARENTS or declared_neighbour(node):
            return False
        items = declarators(node)
        if len(items) != 1 or items[0].child_by_field_name("value") is None:
            return False
        facts = file_facts(node)
        names = pattern_names(items[0].child_by_field_name("name"))
        if facts.opaque or names & facts.logical:
            return False
        scope = node.parent if node.parent.type in ["program", "statement_block"] else node.parent.parent
        return not names & facts.written_in(scope)

    return guard(
        f"{current} of one initialised name that is never assigned in its scope and has no declaration next to it"
    )(test)


def change_keyword(new):
    return lambda node, source: [replace(node.children[0], new)]


# ---------------------------------------------------------------- 26 logical assignment

LOGICAL = {"||": "||=", "&&": "&&=", "??": "??="}
FUNCTION_VALUES = ["function", "arrow_function", "generator_function", "class"]


def logical_site(name, operand, spelled, node):
    """`a = a || b` / `a ||= b` for a name declared by let, var or parameter and never by const, with a plain b
    (an anonymous function would be named `a` by `||=` but not by `||`) and exactly the canonical spelling."""
    facts = file_facts(node)
    a = text(name)
    if facts.opaque or a not in facts.mutable or a in facts.const or not plain_operand(operand):
        return False
    inner = operand
    while inner.type == "parenthesized_expression" and len(inner.children) == 3:
        inner = inner.children[1]
    return (
        inner.type not in FUNCTION_VALUES
        and operand.end_byte == node.end_byte
        and facts.bytes(node.start_byte, operand.start_byte) == spelled.encode()
    )


@guard("a = a || b (also && and ??) for a declared mutable name a and a plain b")
def repeated_assignment(node):
    name, value = node.child_by_field_name("left"), node.child_by_field_name("right")
    if (
        name.type != "identifier"
        or value.type != "binary_expression"
        or operator(value) not in LOGICAL
        or text(value.child_by_field_name("left")) != text(name)
    ):
        return False
    return logical_site(
        name, value.child_by_field_name("right"), f"{text(name)} = {text(name)} {operator(value)} ", node
    )


@guard("a ||= b (also &&= and ??=) for a declared mutable name a and a plain b")
def logical_assignment(node):
    name = node.child_by_field_name("left")
    return (
        name.type == "identifier"
        and operator(node) in LOGICAL.values()
        and logical_site(name, node.child_by_field_name("right"), f"{text(name)} {operator(node)} ", node)
    )


def to_logical_assignment(node, source):
    """a = a || b -> a ||= b"""
    name, value = node.child_by_field_name("left"), node.child_by_field_name("right")
    return [
        Edit(
            node.start_byte, value.child_by_field_name("right").start_byte, f"{text(name)} {LOGICAL[operator(value)]} "
        )
    ]


def to_repeated_assignment(node, source):
    """a ||= b -> a = a || b"""
    name, value = node.child_by_field_name("left"), node.child_by_field_name("right")
    spelled = {assignment: plain for plain, assignment in LOGICAL.items()}[operator(node)]
    return [Edit(node.start_byte, value.start_byte, f"{text(name)} = {text(name)} {spelled} ")]


# ---------------------------------------------------------------- 27 Math.pow / **

POWER_OPERANDS = [
    "identifier",
    "number",
    "member_expression",
    "subscript_expression",
    "call_expression",
    "parenthesized_expression",
]
POWER_PARENTS = [
    "expression_statement",
    "variable_declarator",
    "return_statement",
    "arguments",
    "array",
    "pair",
    "parenthesized_expression",
    "ternary_expression",
    "sequence_expression",
    "spread_element",
    "template_substitution",
    "arrow_function",
    "throw_statement",
    "yield_expression",
    "binary_expression",
]


def power_context(node):
    """Where `Math.pow(a, b)` and `a ** b` can replace each other without parentheses changing, and without
    changing what the assignment rules (2.1/2.2: `x = x + y`, `x += y`) see as the right operand."""
    parent = node.parent
    if parent.type not in POWER_PARENTS:
        return False
    if parent.type == "binary_expression":
        return operator(parent) != "**" and not (
            parent.child_by_field_name("right") == node
            and parent.parent.type in ["assignment_expression", "augmented_assignment_expression"]
        )
    return True


def power_file(node):
    facts = file_facts(node)
    return not facts.opaque and not facts.bigint and "Math" not in facts.bound and "Math" not in facts.base_writes


@guard("Math.pow(a, b) with two plain operands, Math not rebound, no BigInt in the file")
def pow_call(node):
    function, arguments = node.child_by_field_name("function"), node.child_by_field_name("arguments")
    if (
        function.type != "member_expression"
        or function.text != b"Math.pow"
        or arguments.type != "arguments"
        or len(arguments.children) != 5
    ):
        return False
    first, second = arguments.children[1], arguments.children[3]
    return (
        first.type in POWER_OPERANDS
        and second.type in POWER_OPERANDS
        and node.text == b"Math.pow(" + first.text + b", " + second.text + b")"
        and power_context(node)
        and power_file(node)
    )


@guard("a ** b with two plain operands, Math not rebound, no BigInt in the file")
def pow_operator(node):
    left, right = node.child_by_field_name("left"), node.child_by_field_name("right")
    return (
        operator(node) == "**"
        and left.type in POWER_OPERANDS
        and right.type in POWER_OPERANDS
        and node.text == left.text + b" ** " + right.text
        and power_context(node)
        and power_file(node)
    )


def to_pow_operator(node, source):
    """Math.pow(a, b) -> a ** b"""
    arguments = node.child_by_field_name("arguments")
    return [replace(node, f"{text(arguments.children[1])} ** {text(arguments.children[3])}")]


def to_pow_call(node, source):
    """a ** b -> Math.pow(a, b)"""
    return [
        replace(node, f"Math.pow({text(node.child_by_field_name('left'))}, {text(node.child_by_field_name('right'))})")
    ]


# ---------------------------------------------------------------- 28 parseInt / Number.parseInt

PARSERS = ["parseInt", "parseFloat"]


def global_alias_call(member_form):
    """parseInt(...) / parseFloat(...), or the identical Number.parseInt(...) / Number.parseFloat(...) (ES2015
    makes them the same function object), when none of the names is rebound or assigned."""

    def test(node):
        function = node.child_by_field_name("function")
        if any(child.type == "optional_chain" for child in node.children):
            return False
        if member_form:
            if function.type != "member_expression" or function.text not in [
                b"Number." + name.encode() for name in PARSERS
            ]:
                return False
        elif function.type != "identifier" or text(function) not in PARSERS:
            return False
        facts = file_facts(node)
        names = {"Number", *PARSERS}
        return not facts.opaque and not names & facts.bound and not names & facts.base_writes

    return nodes("call_expression").where(guard("Number." + "parseX(...)" if member_form else "parseX(...)")(test))


def to_global_call(node, source):
    """Number.parseInt(...) -> parseInt(...)"""
    function = node.child_by_field_name("function")
    return [replace(function, text(function.child_by_field_name("property")))]


def to_member_call(node, source):
    """parseInt(...) -> Number.parseInt(...)"""
    function = node.child_by_field_name("function")
    return [replace(function, "Number." + text(function))]


# ---------------------------------------------------------------- 29 undefined / void 0


def undefined_context(node):
    """An expression position where `undefined` and `void 0` replace each other without changing the parse."""
    parent = node.parent
    kind = parent.type
    if kind in ["member_expression", "subscript_expression"] and parent.child_by_field_name("object") == node:
        return False
    if kind in ["call_expression", "new_expression"] and node in [
        parent.child_by_field_name("function"),
        parent.child_by_field_name("constructor"),
    ]:
        return False
    if (
        kind in ["assignment_expression", "augmented_assignment_expression", "assignment_pattern", "for_in_statement"]
        and parent.child_by_field_name("left") == node
    ):
        return False
    if kind == "variable_declarator" and parent.child_by_field_name("name") == node:
        return False
    if kind == "binary_expression" and operator(parent) == "**" and parent.child_by_field_name("left") == node:
        return False
    return kind not in [
        "formal_parameters",
        "array_pattern",
        "object_pattern",
        "pair_pattern",
        "rest_pattern",
        "update_expression",
        "class_heritage",
    ]


def undefined_file(node):
    facts = file_facts(node)
    return not facts.opaque and "undefined" not in facts.bound and "undefined" not in facts.base_writes


@guard("the undefined value in an expression position outside comparisons")
def undefined_value(node):
    return undefined_context(node) and outside_equality_operands(node) and undefined_file(node)


@guard("void 0 in an expression position outside comparisons")
def void_zero(node):
    argument = node.child_by_field_name("argument")
    return (
        operator(node) == "void"
        and argument.type == "number"
        and argument.text == b"0"
        and undefined_context(node)
        and outside_equality_operands(node)
        and undefined_file(node)
    )


# ---------------------------------------------------------------- 30 callback function / arrow

CALLBACK_METHODS = [
    "map",
    "filter",
    "forEach",
    "reduce",
    "reduceRight",
    "some",
    "every",
    "find",
    "findIndex",
    "findLast",
    "findLastIndex",
    "flatMap",
    "sort",
]
# Nodes after which `this`, `arguments`, `super` and `new.target` belong to another function.
OWN_THIS = [
    "function",
    "function_declaration",
    "generator_function",
    "generator_function_declaration",
    "method_definition",
    "class",
    "class_declaration",
]


def callback_position(node):
    """An argument of recv.m(...) for an array method m that calls its callback as a plain function: never with
    `new`, never reading `prototype` (a thisArg is only seen by code that uses `this`, which is excluded)."""
    arguments = node.parent
    if arguments.type != "arguments" or arguments.parent.type != "call_expression":
        return False
    function = arguments.parent.child_by_field_name("function")
    if function.type == "member_expression":  # recv.m(...)
        field = function.child_by_field_name("property")
        return field is not None and field.type == "property_identifier" and text(field) in CALLBACK_METHODS
    if function.type == "subscript_expression":  # recv["m"](...), which the member-access rule (19) writes
        index = function.child_by_field_name("index")
        return (
            index is not None
            and index.type == "string"
            and b"\\" not in index.text
            and text(index)[1:-1] in CALLBACK_METHODS
        )
    return False


def function_bound(node):
    """Whether the parameters or body use what a `function` and an arrow bind differently (this, arguments, super,
    new.target), or `yield` / `await` words whose meaning depends on the kind of the enclosing function."""
    stack = list(node.children)
    while stack:
        current = stack.pop()
        kind = current.type
        if (
            kind in ["this", "super", "yield_expression"]
            or (kind == "meta_property" and current.text == b"new.target")
            or (kind == "identifier" and current.text in [b"arguments", b"yield", b"await"])
        ):
            return True
        if kind not in OWN_THIS:
            stack.extend(current.children)
    return False


def plain_parameters(parameters):
    """Parameters an arrow accepts as they are: no duplicate names (allowed only for sloppy-mode functions)."""
    names = [
        text(child)
        for child in descendants(parameters)
        if child.type in ["identifier", "shorthand_property_identifier_pattern"]
    ]
    return len(names) == len(set(names))


def callback_head(node, arrow):
    """`function (a, b) ` / `(a, b) => ` (with `async ` in front for async callbacks): the only spellings either
    direction writes, so the other direction takes exactly these."""
    parameters, body = node.child_by_field_name("parameters"), node.child_by_field_name("body")
    if parameters is None or body is None or body.type != "statement_block":
        return None
    prefix = b"async " if node.children[0].type == "async" else b""
    expected = prefix + (parameters.text + b" => " if arrow else b"function " + parameters.text + b" ")
    return expected if node.text[: body.start_byte - node.start_byte] == expected else None


def callback(arrow):
    def test(node):
        if not arrow and node.child_by_field_name("name") is not None:
            return False
        body = node.child_by_field_name("body")
        return (
            callback_head(node, arrow) is not None
            and returned(body) is None
            and callback_position(node)
            and plain_parameters(node.child_by_field_name("parameters"))
            and not function_bound(node)
        )

    return guard(
        "callback "
        + ("(a) => { ... }" if arrow else "function (a) { ... }")
        + " of an array method, free of this/arguments/super/new.target"
    )(test)


def to_callback_head(arrow):
    """function (a) { ... } <-> (a) => { ... }   (the body is kept as written)"""

    def rewrite(node, source):
        prefix = "async " if node.children[0].type == "async" else ""
        parameters = text(node.child_by_field_name("parameters"))
        head = f"{prefix}{parameters} => " if arrow else f"{prefix}function {parameters} "
        return [Edit(node.start_byte, node.child_by_field_name("body").start_byte, head)]

    return rewrite


# ---------------------------------------------------------------- 31 / 32 [] and {} / new Array() and new Object()


def opens_statement_or_body(node, arrow_body):
    """The node is the first token of an expression statement (where `{` would start a block and `[` would continue
    the previous line) or, when `arrow_body`, of an arrow's expression body (where `{` would start a block body)."""
    current = node
    while current.parent is not None and current.parent.start_byte == node.start_byte:
        if current.parent.type == "expression_statement":
            return True
        current = current.parent
    return (
        arrow_body
        and current.parent is not None
        and current.parent.type == "arrow_function"
        and current.parent.child_by_field_name("body") == current
    )


def arrow_result(node):
    """The value an arrow function returns directly: its expression body (through parentheses) or the `e` of a
    `{ return e; }` body. The arrow-body rule (24) reads whether that value starts with `{`."""
    current = node
    while current.parent.type == "parenthesized_expression":
        current = current.parent
    parent = current.parent
    if parent.type == "arrow_function" and parent.child_by_field_name("body") == current:
        return True
    return (
        parent.type == "return_statement"
        and parent.parent.type == "statement_block"
        and parent.parent.parent is not None
        and parent.parent.parent.type == "arrow_function"
    )


def empty_value_site(node, global_name):
    parent = node.parent
    if parent.type in ["member_expression", "subscript_expression"] and parent.child_by_field_name("object") == node:
        return False
    if parent.type in ["call_expression", "new_expression"] and node in [
        parent.child_by_field_name("function"),
        parent.child_by_field_name("constructor"),
    ]:
        return False
    if opens_statement_or_body(node, arrow_body=global_name == "Object") or (
        global_name == "Object" and arrow_result(node)
    ):
        return False
    facts = file_facts(node)
    return not facts.opaque and global_name not in facts.bound and global_name not in facts.base_writes


def empty_literal(kind, global_name):
    spelled = b"[]" if kind == "array" else b"{}"

    def test(node):
        if node.text != spelled or not empty_value_site(node, global_name):
            return False
        facts = file_facts(node)  # minified `return[]` must not become `returnnew Array()`
        return not fuses(facts.bytes(node.start_byte - 1, node.start_byte), b"", b"new")

    return guard(f"{spelled.decode()} in an expression position, {global_name} not rebound")(test)


def empty_construction(global_name):
    spelled = f"new {global_name}()".encode()
    return guard(f"new {global_name}() in an expression position, {global_name} not rebound")(
        lambda node: node.text == spelled and empty_value_site(node, global_name)
    )


# ---------------------------------------------------------------- registry

EQUALITY_TEST = BINARY.where(operator_in(*EQUALITY), outside_equality_operands)
POSITIVE_TEST = EQUALITY_TEST.where(operator_in("===", "=="), ~negated)
NEGATIVE_TEST = EQUALITY_TEST.where(operator_in("!==", "!="), ~negated)
UPDATE = nodes("update_expression").where(value_unused, one_line_update)

RULES = {
    "2.1": nodes("assignment_expression").where(self_assignment).where(well_formed).rule(to_compound),
    "2.2": nodes("augmented_assignment_expression").where(compound_assignment).where(well_formed).rule(from_compound),
    "2.3": POSITIVE_TEST.where(well_formed).rule(negate_equality),
    "2.4": negated_test(["!==", "!="]).where(well_formed).rule(remove_negation),
    "2.5": NEGATIVE_TEST.where(well_formed).rule(negate_equality),
    "2.6": negated_test(["===", "=="]).where(well_formed).rule(remove_negation),
    "2.7": literal_comparison(literal_on_left=True).where(outside_equality_operands).where(well_formed).rule(mirror),
    "2.8": literal_comparison(literal_on_left=False).where(outside_equality_operands).where(well_formed).rule(mirror),
    "2.11": SIMPLE_EQUALITY.where(well_formed).rule(hash_order(equality_rule=True, swap_when_left_hash_larger=True)),
    "2.12": SIMPLE_EQUALITY.where(well_formed).rule(hash_order(equality_rule=True, swap_when_left_hash_larger=False)),
    "2.13": SIMPLE_EQUALITY.where(well_formed).rule(hash_order(equality_rule=False, swap_when_left_hash_larger=True)),
    "2.14": SIMPLE_EQUALITY.where(well_formed).rule(hash_order(equality_rule=False, swap_when_left_hash_larger=False)),
    "3.1": UPDATE.where(prefix_form(False)).where(well_formed).rule(flip_update),
    "3.2": UPDATE.where(prefix_form(True)).where(well_formed).rule(flip_update),
    "6.1": Matcher("[(lexical_declaration) (variable_declaration)] @node")
    .where(splittable_cluster)
    .where(well_formed)
    .rule(split_declaration),
    "6.2": Matcher("[(lexical_declaration) (variable_declaration)] @node")
    .where(mergeable_cluster)
    .where(well_formed)
    .rule(merge_declarations),
    "7.1": nodes("for_statement").where(condition_only_for).where(well_formed).rule(for_to_while),
    "7.2": nodes("while_statement").where(plain_while).where(well_formed).rule(while_to_for),
    "14.1": braced_if_else(negated_form=True).where(well_formed).rule(swap_branches(negate=False)),
    "14.2": braced_if_else(negated_form=False).where(well_formed).rule(swap_branches(negate=True)),
    "15.1": movable_conditional(negated_form=True).where(well_formed).rule(swap_conditional(negate=False)),
    "15.2": movable_conditional(negated_form=False).where(well_formed).rule(swap_conditional(negate=True)),
    "16.1": nodes("if_statement").where(nested_if).where(well_formed).rule(join_conjunction),
    "16.2": nodes("if_statement").where(conjunctive_if).where(well_formed).rule(split_conjunction),
    "18.1": Matcher(FUNCTIONS).where(ends_with_bare_return).where(well_formed).rule(drop_final_return),
    "18.2": Matcher(FUNCTIONS).where(ends_without_return).where(well_formed).rule(add_final_return),
    "19.1": nodes("subscript_expression")
    .where(bracket_access, outside_equality_operands)
    .where(well_formed)
    .rule(to_dot),
    "19.2": nodes("member_expression").where(dot_access, outside_equality_operands).where(well_formed).rule(to_bracket),
    "20.1": nodes("if_statement").where(exiting_braced_if_then_rest).where(well_formed).rule(add_braced_else),
    "20.2": nodes("if_statement").where(exiting_braced_if_else).where(well_formed).rule(drop_braced_else),
    "24.1": nodes("arrow_function").where(returning_arrow).where(well_formed).rule(to_expression_body),
    "24.2": nodes("arrow_function").where(concise_arrow).where(well_formed).rule(to_block_body),
    "25.1": nodes("lexical_declaration").where(never_written("let")).where(well_formed).rule(change_keyword("const")),
    "25.2": nodes("lexical_declaration").where(never_written("const")).where(well_formed).rule(change_keyword("let")),
    "26.1": nodes("augmented_assignment_expression")
    .where(logical_assignment)
    .where(well_formed)
    .rule(to_repeated_assignment),
    "26.2": nodes("assignment_expression").where(repeated_assignment).where(well_formed).rule(to_logical_assignment),
    "27.1": nodes("binary_expression").where(pow_operator).where(well_formed).rule(to_pow_call),
    "27.2": nodes("call_expression").where(pow_call).where(well_formed).rule(to_pow_operator),
    "28.1": global_alias_call(member_form=True).where(well_formed).rule(to_global_call),
    "28.2": global_alias_call(member_form=False).where(well_formed).rule(to_member_call),
    "29.1": nodes("unary_expression")
    .where(void_zero)
    .where(well_formed)
    .rule(lambda node, source: [replace(node, "undefined")]),
    "29.2": nodes("undefined")
    .where(undefined_value)
    .where(well_formed)
    .rule(lambda node, source: [replace(node, "void 0")]),
    "30.1": nodes("arrow_function").where(callback(arrow=True)).where(well_formed).rule(to_callback_head(arrow=False)),
    "30.2": nodes("function").where(callback(arrow=False)).where(well_formed).rule(to_callback_head(arrow=True)),
    "31.1": nodes("new_expression")
    .where(empty_construction("Array"))
    .where(well_formed)
    .rule(lambda node, source: [replace(node, "[]")]),
    "31.2": nodes("array")
    .where(empty_literal("array", "Array"))
    .where(well_formed)
    .rule(lambda node, source: [replace(node, "new Array()")]),
    "32.1": nodes("new_expression")
    .where(empty_construction("Object"))
    .where(well_formed)
    .rule(lambda node, source: [replace(node, "{}")]),
    "32.2": nodes("object")
    .where(empty_literal("object", "Object"))
    .where(well_formed)
    .rule(lambda node, source: [replace(node, "new Object()")]),
    "23.1": nodes("pair")
    .where(explicit_property, outside_equality_operands)
    .where(well_formed)
    .rule(lambda node, source: [replace(node, text(node.child_by_field_name("key")))]),
    "23.2": nodes("shorthand_property_identifier")
    .where(shorthand_property, outside_equality_operands)
    .where(well_formed)
    .rule(lambda node, source: [replace(node, f"{text(node)}: {text(node)}")]),
}

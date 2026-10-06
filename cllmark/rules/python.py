"""Python rewrite rules, keyed by style id (see styles.json).

Each rule is a tree-sitter pattern for the candidate's shape, guards for context the
pattern cannot express, and a node-anchored rewrite. Rules ported from the original
operators keep their candidate conditions and output text.
"""

import hashlib

from .engine import (
    Edit,
    Matcher,
    Reject,
    delete,
    delete_between,
    guard,
    insert_after,
    insert_before,
    replace,
    text,
    well_formed,
)


def child_count(count):
    return guard(f"{count} children")(lambda node: len(node.children) == count)


def nodes(node_type):
    return Matcher(f"(({node_type}) @node)")


# ---------------------------------------------------------------- print(...)

PRINT_CALL = Matcher('((call function: _ @_f) @node (#eq? @_f "print"))')


def keyword_arguments(call, name):
    """Arguments whose `name` field is `name` (keyword arguments, but also walrus targets)."""
    return [
        argument
        for argument in call.child_by_field_name("arguments").children
        if (key := argument.child_by_field_name("name")) is not None and key.text == name
    ]


def passes(name, *values):
    shown = "|".join(value.decode() for value in values) if values else "..."
    return guard(f"passes {name.decode()}={shown}")(
        lambda node: any(
            not values or argument.child_by_field_name("value").text in values
            for argument in keyword_arguments(node, name)
        )
    )


def add_keyword(argument_text):
    """print(x) -> print(x, <argument_text>)   (not after a generator argument or a trailing comma: invalid syntax)"""

    def rewrite(node, source):
        arguments = node.child_by_field_name("arguments")
        if arguments.type != "argument_list" or (len(arguments.children) > 2 and arguments.children[-2].type == ","):
            raise Reject("generator argument or trailing comma")
        separator = "" if len(arguments.children) == 2 else ", "
        return [insert_before(arguments.children[-1], separator + argument_text)]

    return rewrite


def drop_keyword(name):
    """print(x, flush=True) -> print(x): removes the first `name` argument and its separator."""

    def rewrite(node, source):
        arguments = node.child_by_field_name("arguments")
        if len(arguments.children) == 3:
            return [Edit(arguments.start_byte + 1, arguments.end_byte - 1)]
        comma = None
        for argument in arguments.children:
            if argument.type == ",":
                comma = argument
            elif argument in keyword_arguments(node, name):
                if comma is not None:
                    return [delete_between(comma.start_byte, argument.end_byte)]
                following = argument.next_named_sibling
                return [
                    delete_between(
                        argument.start_byte, following.start_byte if following else argument.next_sibling.end_byte
                    )
                ]
        return []

    return rewrite


# ---------------------------------------------------------------- list / dict / range calls


def call_to(name, argument_children):
    """name(...) whose argument list has `argument_children` children, parentheses included."""
    return Matcher(
        f'((call function: _ @_f) @node (#eq? @_f "{name}"))',
        (
            guard(f"{argument_children} argument children")(
                lambda node: len(node.child_by_field_name("arguments").children) == argument_children
            ),
        ),
    )


def first_argument(node):
    return node.child_by_field_name("arguments").children[1]


def first_argument_is(node_type, nonempty=False):
    return guard(f"argument is {'non-empty ' if nonempty else ''}{node_type}")(
        lambda node: first_argument(node).type == node_type and (not nonempty or len(first_argument(node).children) > 2)
    )


def not_argument_of(name):
    """Literal not passed straight to name(...): its grandparent's first child is not `name`."""
    return guard(f"not wrapped in {name.decode()}()")(lambda node: node.parent.parent.children[0].text != name)


def wrap_in(name):
    return lambda node, source: [insert_before(node, name + "("), insert_after(node, ")")]


def unwrap_call(node, source):
    """name([...]) -> [...]"""
    arguments = node.child_by_field_name("arguments")
    return [delete_between(node.start_byte, arguments.children[1].start_byte), delete(arguments.children[2])]


def add_range_start(node, source):
    """range(n) -> range(0, n)   (not for range(*args), whose meaning would change)"""
    if first_argument(node).type in ["list_splat", "dictionary_splat", "keyword_argument"]:
        raise Reject("unpacked or keyword argument")
    opening = node.child_by_field_name("arguments").children[0]
    return [insert_after(opening, "0, ")]


def del_range_start(node, source):
    """range(0, n) -> range(n)"""
    arguments = node.child_by_field_name("arguments")
    return [delete_between(arguments.children[0].end_byte, arguments.children[3].start_byte)]


zero_start = guard("starts at 0")(
    lambda node: first_argument(node).type == "integer" and first_argument(node).text == b"0"
)

# ---------------------------------------------------------------- slices

SLICE = nodes("subscript").where(guard("first index is a slice")(lambda node: node.children[2].type == "slice"))


def slice_halves(node):
    """(slice node, byte offset of ':', text before ':', text after ':') for exactly one ':' in the text."""
    piece = node.children[2]
    value = text(piece)
    if value.count(":") != 1:
        raise Reject("not a single-colon slice")
    left, right = value.split(":")
    return piece, piece.start_byte + len(left.encode("utf-8")), left, right


def negative_count(node, right):
    """a[:-k] equals a[:len(a)-k] only for k > 0 and an `a` that is safe to evaluate twice."""
    return node.children[0].type == "identifier" and right[1:].strip().isdigit() and int(right[1:].strip()) > 0


def add_slice_index(node, source):
    """a[:n] -> a[0:n];  a[:-k] -> a[:len(a)-k]"""
    piece, colon, left, right = slice_halves(node)
    edits = [insert_before(piece, "0")] if left == "" else []
    if right.startswith("-") and negative_count(node, right):
        edits.append(Edit(colon + 1, colon + 1, f"len({text(node.children[0])})"))
    return edits


def del_slice_index(node, source):
    """a[0:n] -> a[:n];  a[:len(a)-n] -> a[:-n]"""
    _piece, colon, left, right = slice_halves(node)
    edits = [Edit(colon - 1, colon)] if left == "0" else []
    if f"len({text(node.children[0])})-" in right.replace(" ", "") and negative_count(
        node, "-" + right.split("-", 1)[1]
    ):
        edits.append(delete_between(colon + 1, colon + 1 + right.encode("utf-8").index(b"-")))
    return edits


# ---------------------------------------------------------------- string literals


def not_triple_quoted(node):
    if '"""' in text(node) or "'''" in text(node):
        raise Reject("triple-quoted string")


def requote(quote, other):
    """Outer quotes become `quote` (the original operator's text rule). Strings whose content holds
    `quote` are left alone: the original rule turned those characters into `other`, changing the value."""

    def rewrite(node, source):
        not_triple_quoted(node)
        ancestor = node.parent
        while ancestor is not None:
            if ancestor.type == "interpolation":
                # f"{','.join(x)}" -> f"{",".join(x)}" reuses the enclosing quote: a syntax error before Python 3.12.
                raise Reject("inside an f-string replacement field")
            ancestor = ancestor.parent
        start, end = node.children[0], node.children[-1]
        if quote in source.data[start.end_byte : end.start_byte].decode("utf-8"):
            raise Reject("content holds the target quote")
        value = text(node).replace(quote, other)
        first, last = value.find(other), value.rfind(other)
        return [replace(node, value[:first] + quote + value[first + 1 : last] + quote + value[last + 1 :])]

    return rewrite


def literal_without_interpolation(f_prefix):
    def test(node):
        start = text(node.children[0])
        return (
            not any(child.type == "interpolation" for child in node.children)
            and "b" not in start
            and "r" not in start
            and ("f" in start) == f_prefix
            and not any(prefix in start for prefix in "BRUuF")
            and "{" not in text(node)
            and "}" not in text(node)
        )

    return guard("f-string without interpolation" if f_prefix else "str literal without prefix f/b/r")(test)


def set_prefix(transform):
    def rewrite(node, source):
        not_triple_quoted(node)
        return [replace(node.children[0], transform(text(node.children[0])))]

    return rewrite


# ---------------------------------------------------------------- operators

RELATIONAL = [">", ">=", "<", "<="]
EQUALITY = ["==", "!="]
COMPARISON = nodes("comparison_operator")
binary = child_count(3)


def operator_in(*operators):
    return guard("operator " + "|".join(operators))(
        lambda node: node.children[1].text != b"in" and text(node.children[1]) in operators
    )


def operands(node):
    return [text(child) for child in node.children]


@guard("directly inside not (...)")
def negated(node):
    parent = node.parent
    return (
        parent is not None
        and parent.type == "parenthesized_expression"
        and len(parent.children) == 3
        and parent.parent is not None
        and parent.parent.type == "not_operator"
    )


# ---------------------------------------------------------------- functional safety of the comparison rules
#
# Real code compares numpy arrays and other element-wise types: `A[A != 0] = 1` is a mask, `not (A == 0)` and
# `(a < b or a == b)` raise on arrays, and the expansion evaluates its operands twice. So negation (7.3-7.6) and
# expcmp (7.9/7.10) only rewrite comparisons whose value is used as a truth value anyway (where an array would
# already raise in the original code), and expcmp only with operands free of side effects. Both forms of a pair sit
# in the same place, so these guards keep each pair's candidates the same in either direction.


def truth_tested(node):
    """The value of `node` (through parentheses) is only used as a truth value: a condition of if/elif/while/assert,
    a comprehension filter or a conditional expression, or an operand of not/and/or."""
    current = node
    while current.parent is not None and current.parent.type == "parenthesized_expression":
        current = current.parent
    parent = current.parent
    if parent is None:
        return False
    if parent.type in ["if_statement", "elif_clause", "while_statement"]:
        return parent.child_by_field_name("condition") == current
    if parent.type == "assert_statement":
        return parent.named_children[0] == current
    if parent.type == "conditional_expression":
        return len(parent.children) == 5 and parent.children[2] == current
    return parent.type in ["not_operator", "boolean_operator", "if_clause"]


boolean_context = guard("value used only as a truth value")(truth_tested)

PURE_CALLS = {b"len", b"abs", b"ord", b"chr", b"int", b"float", b"str", b"round", b"min", b"max"}
IMPURE = ["await", "yield", "named_expression", "lambda", "list_comprehension", "generator_expression"]


def side_effect_free(node):
    stack = [node]
    while stack:
        current = stack.pop()
        if current.type in IMPURE:
            return False
        if current.type == "call" and current.child_by_field_name("function").text not in PURE_CALLS:
            return False
        stack.extend(current.children)
    return True


def numeric_operand(node):
    """A number literal (possibly negated) or len(...): a comparison with one is a comparison of numbers."""
    if node.type == "unary_operator" and len(node.children) == 2:
        node = node.children[1]
    if node.type in ["integer", "float"]:
        return True
    return node.type == "call" and node.child_by_field_name("function").text == b"len"


@guard("numbers compared with operands free of side effects: expcmp evaluates them twice, and `a < b or a == b`")
def pure_comparison(node):
    """... equals `a <= b` only for a total order consistent with ==, which objects need not have (a heap entry's
    `<` compares priorities, its `==` identity)."""
    if node.type == "parenthesized_expression":  # (a < b or a == b)
        node = node.children[1].children[0]
    left, right = node.children[0], node.children[2]
    return (numeric_operand(left) or numeric_operand(right)) and side_effect_free(left) and side_effect_free(right)


def numeric_assignments(scope, name):
    """Whether `scope` (a function body or module, not nested functions) assigns a number literal to `name`."""
    stack = list(scope.children)
    while stack:
        current = stack.pop()
        if current.type in ["function_definition", "class_definition", "lambda"]:
            continue
        if current.type == "assignment" and len(current.children) == 3 and text(current.children[0]) == name:
            value = current.children[2]
            if value.type == "unary_operator" and len(value.children) == 2:
                value = value.children[1]
            if value.type in ["integer", "float"]:
                return True
        stack.extend(current.children)
    return False


@guard("a variable that its function also sets to a number: `a = a - b` -> `a -= b` would mutate a list, set or array")
def numeric_variable(node):
    target = node.children[0]
    if target.type != "identifier":
        return False
    scope = node.parent
    while scope is not None and scope.type not in ["function_definition", "module"]:
        scope = scope.parent
    return scope is not None and numeric_assignments(scope, text(target))


def expanded_junction(junction):
    """`a < b or a == b`: and/or of a relational and an equality test on the same two operands."""
    if (
        junction.type != "boolean_operator"
        or len(junction.children) != 3
        or text(junction.children[1]) not in ["and", "or"]
    ):
        return False
    first, second = junction.children[0], junction.children[2]
    return (
        first.type == "comparison_operator"
        and second.type == "comparison_operator"
        and text(first.children[1]) in RELATIONAL
        and text(second.children[1]) in EQUALITY
        and {text(first.children[0]).strip(), text(first.children[2]).strip()}
        == {text(second.children[0]).strip(), text(second.children[2]).strip()}
    )


@guard("operand of a parenthesized expanded comparison")
def in_expanded_comparison(node):
    junction = node.parent
    return (
        junction is not None
        and junction.parent is not None
        and junction.parent.type == "parenthesized_expression"
        and expanded_junction(junction)
    )


@guard("(a < b or a == b) with simple comparisons")
def expanded_comparison(node):
    if len(node.children) != 3 or not expanded_junction(node.children[1]):
        return False
    return len(node.children[1].children[0].children) == 3 and len(node.children[1].children[2].children) == 3


def negate_equality(operator, inverse):
    """a == b -> not (a != b)"""

    def rewrite(node, source):
        a, current, b = operands(node)
        if current != operator:
            raise Reject("other operator")
        return [replace(node, f"not ({a} {inverse} {b})")]

    return rewrite


def negated_test(inner):
    """not (a <inner> b)"""

    def test(node):
        if len(node.children) != 2 or text(node.children[0]) != "not":
            return False
        group = node.children[1]
        if group.type != "parenthesized_expression" or len(group.children) != 3:
            return False
        comparison = group.children[1]
        return (
            comparison.type == "comparison_operator"
            and len(comparison.children) == 3
            and text(comparison.children[1]) == inner
        )

    return nodes("not_operator").where(guard(f"not (a {inner} b)")(test))


def remove_negation(operator):
    """not (a != b) -> a == b"""

    def rewrite(node, source):
        a, _, b = operands(node.children[1].children[1])
        return [replace(node, f"{a} {operator} {b}")]

    return rewrite


def mirror(operators):
    """a < b -> b > a for the given operators"""
    flipped = {"<": ">", "<=": ">=", ">": "<", ">=": "<="}

    def rewrite(node, source):
        a, operator, b = operands(node)
        if operator not in operators:
            raise Reject("other operator")
        return [replace(node, f"{b} {flipped[operator]} {a}")]

    return rewrite


EXPAND = {
    "<=": "({a} < {b} or {a} == {b})",
    "<": "({a} <= {b} and {a} != {b})",
    ">=": "({a} > {b} or {a} == {b})",
    ">": "({a} >= {b} and {a} != {b})",
}
CONTRACT = {">": ">=", "<": "<=", ">=": ">", "<=": "<"}


def expand_comparison(node, source):
    """a <= b -> (a < b or a == b)"""
    a, operator, b = operands(node)
    return [replace(node, EXPAND[operator].format(a=a, b=b))]


def contract_comparison(node, source):
    """(a < b or a == b) -> a <= b"""
    a, operator, b = operands(node.children[1].children[0])
    return [replace(node, f"{a} {CONTRACT[operator]} {b}")]


def hash_at_least(left, right):
    return int(hashlib.sha256(left.encode("utf-8")).hexdigest(), 16) >= int(
        hashlib.sha256(right.encode("utf-8")).hexdigest(), 16
    )


def hash_order(operator, operator_when_negated, swap_when_left_hash_larger):
    """a == b -> b == a when the operand order disagrees with their SHA-256 order."""

    def rewrite(node, source):
        a, current, b = operands(node)
        if current != (operator_when_negated if negated(node) else operator):
            raise Reject("other operator")
        if hash_at_least(a, b) != swap_when_left_hash_larger:
            raise Reject("already in order")
        return [replace(node, f"{b} {current} {a}")]

    return rewrite


SELF_ASSIGNMENT = Matcher("((assignment left: _ @_l right: (binary_operator left: _ @_r)) @node (#eq? @_l @_r))").where(
    guard("no type annotation")(lambda node: node.children[2].type == "binary_operator")
)


def to_augmented(node, source):
    """a = a + b -> a += b"""
    right = node.children[2]
    return [
        replace(node, f"{text(node.child_by_field_name('left'))} {text(right.children[1])}= {text(right.children[2])}")
    ]


BINDING = {"|": 1, "^": 2, "&": 3, "<<": 4, ">>": 4, "+": 5, "-": 5, "*": 6, "@": 6, "/": 6, "//": 6, "%": 6, "**": 8}
LOOSE = [
    "conditional_expression",
    "lambda",
    "boolean_operator",
    "not_operator",
    "comparison_operator",
    "named_expression",
]


def from_augmented(node, source):
    """a += b -> a = a + b   (only when b binds tighter than +; `a += x if c else y` would change meaning)"""
    a, operator, b = operands(node)
    value, binding = node.children[2], BINDING[operator[:-1]]
    if value.type in LOOSE or (
        value.type == "binary_operator"
        and (
            BINDING[text(value.children[1])] < binding
            or (BINDING[text(value.children[1])] == binding and operator != "**=")
        )
    ):
        raise Reject("right side binds more loosely than the operator")
    return [replace(node, f"{a} = {a} {operator[:-1]} {b}")]


# ---------------------------------------------------------------- multiple assignment


def tuple_assignment(equal_values):
    def test(node):
        if node.children[0].type != "pattern_list" or node.children[2].type != "expression_list":
            return False
        values = [child.text for child in node.children[2].children if child.text != b","]
        return not equal_values or all(value == node.children[2].children[0].text for value in values)

    return nodes("assignment").where(guard("a, b = c, d" + (" with equal values" if equal_values else ""))(test))


def unpacked(node):
    targets = text(node.children[0]).replace(" ", "").split(",")
    values = text(node.children[2]).replace(" ", "").split(",")
    if len(targets) != len(values):
        raise Reject("different arity")
    return targets, values


def split_assignment(node, source):
    """a, b = c, d -> a = c / b = d on separate lines"""
    targets, values = unpacked(node)
    separator = "\n" + source.indent(node.start_byte) * " "
    return [
        replace(node, separator.join(f"{target} = {value}" for target, value in zip(targets, values, strict=False)))
    ]


def chain_assignment(node, source):
    """a, b = c, c -> a = b = c"""
    targets, values = unpacked(node)
    return [replace(node, " = ".join([*targets, values[0]]))]


# ---------------------------------------------------------------- return

RETURN = nodes("return_statement")


def returns(node_type):
    return RETURN.where(
        guard(f"returns {node_type}")(lambda node: len(node.children) > 1 and node.children[1].type == node_type)
    )


def strip_parentheses(node, source):
    """return (a, b) -> return a, b   (not `return ()`, which would return None, and not a tuple over several
    lines: without its parentheses `return` would end at the first line break)"""
    value = node.children[1]
    if not any(child.is_named for child in value.children):
        raise Reject("empty tuple")
    if b"\n" in value.text:
        raise Reject("tuple over several lines")
    return [Edit(value.start_byte, value.start_byte + 1), Edit(value.end_byte - 1, value.end_byte)]


# ---------------------------------------------------------------- extension rules (styles 14-21)
#
# Each pair rewrites syntax that the rules above never match, keeps out of comparison
# operands and expanded comparisons (the hash-order and cmp rules read that text), and
# decides candidacy from properties both forms of every other pair share, so applying one
# never creates or removes another rule's candidates. Both directions are exact inverses
# for the canonical layout they emit; bit 0 of each pair is the form ordinary code uses.

PRIMARY = ["identifier", "attribute", "call", "subscript"]
STATEMENTS_WITH_EXIT = ["return_statement", "raise_statement"]


@guard("outside ==/!=/relational operands and expanded comparisons")
def outside_text_sensitive_operands(node):
    """The hash-order rules read ==/!= operand text and expcmp turns relational tests into
    expanded ==/!= tests, so rewriting inside any of them could change those rules' view."""
    parent = node.parent
    while parent is not None and parent.type not in ["block", "module", "expression_statement"]:
        if parent.type == "comparison_operator" and any(
            text(child) in EQUALITY + RELATIONAL for child in parent.children[1::2]
        ):
            return False
        if parent.type == "boolean_operator" and expanded_junction(parent):
            return False
        parent = parent.parent
    return True


def binds(root, name):
    """Whether `name` is (re)bound anywhere in the module: assignment, parameter, def/class, import, loop target..."""
    stack = [root]
    while stack:
        node = stack.pop()
        if node.type == "identifier" and node.text == name:
            parent = node.parent
            field_parents = {
                "function_definition": "name",
                "class_definition": "name",
                "assignment": "left",
                "augmented_assignment": "left",
                "for_statement": "left",
                "for_in_clause": "left",
                "named_expression": "name",
                "aliased_import": "alias",
                "keyword_argument": None,
            }
            if parent.type in [
                "parameters",
                "lambda_parameters",
                "typed_parameter",
                "default_parameter",
                "typed_default_parameter",
                "pattern_list",
                "tuple_pattern",
                "list_pattern",
                "global_statement",
                "nonlocal_statement",
                "as_pattern_target",
                "dotted_name",
                "list_splat_pattern",
                "dictionary_splat_pattern",
            ]:
                return True
            if (
                parent.type in field_parents
                and field_parents[parent.type]
                and parent.child_by_field_name(field_parents[parent.type]) == node
            ):
                return True
        stack.extend(node.children)
    return False


def builtin_call(name, positional):
    """name(<positional> plain arguments) where `name` is the builtin (never rebound in the module)."""

    def test(node):
        arguments = node.child_by_field_name("arguments")
        values = [child for child in arguments.children if child.is_named and child.type != "comment"]
        if arguments.type != "argument_list" or len(values) != positional:
            return False
        if any(
            value.type in ["keyword_argument", "list_splat", "dictionary_splat", "parenthesized_list_splat"]
            for value in values
        ):
            return False
        root = node
        while root.parent is not None:
            root = root.parent
        return not binds(root, name.encode())

    return Matcher(f'((call function: (identifier) @_f) @node (#eq? @_f "{name}"))').where(
        guard(f"builtin {name} with {positional} positional arguments")(test), outside_text_sensitive_operands
    )


def last_argument(node):
    return [child for child in node.child_by_field_name("arguments").children if child.is_named][-1]


def append_argument(value):
    """sum(x) -> sum(x, 0)"""
    return lambda node, source: [insert_after(last_argument(node), f", {value}")]


def drop_last_argument(node, source):
    """sum(x, 0) -> sum(x)"""
    values = [child for child in node.child_by_field_name("arguments").children if child.is_named]
    return [delete_between(values[-2].end_byte, values[-1].end_byte)]


def argument_text(index, value):
    return guard(f"argument {index} is {value}")(
        lambda node: (
            text([child for child in node.child_by_field_name("arguments").children if child.is_named][index]) == value
        )
    )


def two_word_test(first, second):
    """x not in y / x is not y: a single comparison whose operator is two tokens."""
    return COMPARISON.where(
        guard(f"x {first} {second} y")(
            lambda node: (
                len(node.children) == 4
                and node.children[1].text == first.encode()
                and node.children[2].text == second.encode()
            )
        ),
        outside_text_sensitive_operands,
    )


def negated_comparison(operator):
    """not x in y / not x is y"""
    return nodes("not_operator").where(
        guard(f"not x {operator} y")(
            lambda node: (
                node.children[1].type == "comparison_operator"
                and len(node.children[1].children) == 3
                and text(node.children[1].children[1]) == operator
            )
        ),
        outside_text_sensitive_operands,
    )


def lift_not(operator):
    """x not in y -> not x in y   (comparisons bind tighter than not, so no parentheses are needed)"""
    return lambda node, source: [replace(node, f"not {text(node.children[0])} {operator} {text(node.children[3])}")]


def sink_not(combined):
    """not x in y -> x not in y"""

    def rewrite(node, source):
        comparison = node.children[1]
        return [replace(node, f"{text(comparison.children[0])} {combined} {text(comparison.children[2])}")]

    return rewrite


def plain_or_negated(condition, negated_form):
    if negated_form:
        return condition.type == "not_operator" and condition.children[1].type in PRIMARY
    return condition.type in PRIMARY


def contains(node, predicate):
    stack = list(node.children)
    while stack:
        current = stack.pop()
        if predicate(current):
            return True
        stack.extend(current.children)
    return False


def has_else(node):
    return node.type == "if_statement" and any(child.type in ["elif_clause", "else_clause"] for child in node.children)


def nested_branching(node):
    """An if/else, or an exiting if that the else-after-return rule may give an else."""
    return has_else(node) or (node.type == "if_statement" and exits(node.child_by_field_name("consequence")))


def if_else(negated_form):
    """if <primary>: A else: B  (or if not <primary>: ...) with two swappable, non-exiting blocks.

    Blocks holding another if/else are left alone, so nested candidates never overlap.
    """

    def test(node):
        alternatives = [child for child in node.children if child.type in ["elif_clause", "else_clause"]]
        if len(alternatives) != 1 or alternatives[0].type != "else_clause":
            return False
        consequence, alternative = node.child_by_field_name("consequence"), alternatives[0].child_by_field_name("body")
        return (
            plain_or_negated(node.child_by_field_name("condition"), negated_form)
            and not exits(consequence)
            and not exits(alternative)
            and not contains(consequence, nested_branching)
            and not contains(alternative, nested_branching)
        )

    return nodes("if_statement").where(guard("if not <name>/else" if negated_form else "if <name>/else")(test))


def swap_branches(negate):
    """if c: A else: B -> if not c: B else: A   (and back)"""

    def rewrite(node, source):
        condition = node.child_by_field_name("condition")
        consequence = node.child_by_field_name("consequence")
        alternative = [child for child in node.children if child.type == "else_clause"][0].child_by_field_name("body")
        indent = source.leading(consequence)
        if indent is None or indent != source.leading(alternative):
            raise Reject("blocks are not on their own lines at one indentation")
        flipped = "not " + text(condition) if negate else text(condition.children[1])
        return [
            replace(condition, flipped),
            replace(consequence, text(alternative)),
            replace(alternative, text(consequence)),
        ]

    return rewrite


def conditional(negated_form):
    """a if <primary> else b, where b may move to the front (not itself a conditional or lambda)."""
    nested = lambda node: node.type == "conditional_expression"
    return nodes("conditional_expression").where(
        guard("a if c else b with a movable alternative")(
            lambda node: (
                len(node.children) == 5
                and node.children[4].type not in ["conditional_expression", "lambda"]
                and not contains(node, nested)
                and plain_or_negated(node.children[2], negated_form)
            )
        ),
        outside_text_sensitive_operands,
    )


def swap_conditional(negate):
    """a if c else b -> b if not c else a   (and back; the operands trade places, layout kept)"""

    def rewrite(node, source):
        a, _, condition, _, b = node.children
        flipped = "not " + text(condition) if negate else text(condition.children[1])
        return [replace(a, text(b)), replace(condition, flipped), replace(b, text(a))]

    return rewrite


NEGATABLE = [
    *PRIMARY,
    "comparison_operator",
    "not_operator",
    "parenthesized_expression",
    "binary_operator",
    "unary_operator",
    "integer",
    "string",
]


def unwrap(node):
    while node.type == "parenthesized_expression" and len(node.children) == 3:
        node = node.children[1]
    return node


def equality_core(node):
    """(a == b) or (not (a == b)): both forms the ==/!= rules convert between."""
    node = unwrap(node)
    if node.type == "not_operator":
        node = unwrap(node.children[1])
    return node.type == "comparison_operator" and any(text(child) in EQUALITY for child in node.children[1::2])


def negatable_condition(condition):
    """`not C` reparses as not (C) (C binds at least as tightly as not), keeps every rewrite other rules
    make inside C valid, and is no candidate of the membership/identity rules (C is not `x in y`)."""
    if condition.type not in NEGATABLE:
        return False
    if condition.type == "parenthesized_expression" and equality_core(condition):
        return False  # not (a == b) is the negated form the equality rules treat specially
    return not (
        condition.type == "comparison_operator"
        and len(condition.children) == 3
        and text(condition.children[1]) in ["in", "is"]
    )


def plain_while(node):
    body = node.child_by_field_name("body")
    return (
        node.child_by_field_name("alternative") is None
        and node.children[1].type != "true"
        and negatable_condition(node.children[1])
        and body.start_point[0] > node.start_point[0]
    )


def while_true_with_break(node):
    """while True:\\n  if not C:\\n    break\\n  <more statements>"""
    body = node.child_by_field_name("body")
    statements = [child for child in body.children if child.type != "comment"]
    if node.child_by_field_name("alternative") is not None or node.children[1].type != "true" or len(statements) < 2:
        return False
    first = statements[0]
    if first.type != "if_statement" or any(child.type in ["elif_clause", "else_clause"] for child in first.children):
        return False
    condition, block = first.child_by_field_name("condition"), first.child_by_field_name("consequence")
    return (
        condition.type == "not_operator"
        and negatable_condition(condition.children[1])
        and [child.type for child in block.children] == ["break_statement"]
        and block.start_point[0] > first.start_point[0]
    )


def to_while_true(node, source):
    """while C: body -> while True: if not C: break; body"""
    condition, first = node.children[1], node.child_by_field_name("body").children[0]
    indent = source.leading(first)
    if indent is None:
        raise Reject("loop body does not start its own line")
    unit = "\t" if indent.endswith("\t") else "    "
    return [
        replace(condition, "True"),
        insert_before(first, f"if not {text(condition)}:\n{indent}{unit}break\n{indent}"),
    ]


def from_while_true(node, source):
    """while True: if not C: break; body -> while C: body"""
    statements = [child for child in node.child_by_field_name("body").children if child.type != "comment"]
    guard_statement = statements[0]
    condition = guard_statement.child_by_field_name("condition").children[1]
    return [
        replace(node.children[1], text(condition)),
        delete_between(guard_statement.start_byte, guard_statement.next_sibling.start_byte),
    ]


def has_multiline_string(node):
    stack = [node]
    while stack:
        current = stack.pop()
        if current.type == "string" and current.start_point[0] != current.end_point[0]:
            return True
        stack.extend(current.children)
    return False


def reindent(source, start, end, old, new):
    """Text of [start, end) with every following line's `old` indentation prefix replaced by `new`."""
    lines = source.data[start:end].decode("utf-8").split("\n")
    return "\n".join(lines[:1] + [new + line[len(old) :] if line.startswith(old) else line for line in lines[1:]])


def last_in_block(node):
    following = node.next_named_sibling
    while following is not None and following.type == "comment":
        following = following.next_named_sibling
    return following is None


def exits(block):
    """The block always leaves the function: it ends with return/raise, or with an if/elif/else
    whose every branch exits (so both forms of this rule count as exiting)."""
    items = [child for child in block.children if child.type != "comment"]
    if not items:
        return False
    last = items[-1]
    if last.type in STATEMENTS_WITH_EXIT:
        return True
    if last.type != "if_statement":
        return False
    clauses = [child for child in last.children if child.type in ["elif_clause", "else_clause"]]
    if not clauses or clauses[-1].type != "else_clause":
        return False
    bodies = [last.child_by_field_name("consequence")] + [
        clause.child_by_field_name("consequence" if clause.type == "elif_clause" else "body") for clause in clauses
    ]
    return all(exits(body) for body in bodies)


def exiting_if(node):
    return node.type == "if_statement" and exits(node.child_by_field_name("consequence"))


def bare_exiting_if(node):
    return exiting_if(node) and not has_else(node)


def exiting_if_else(node):
    alternatives = [child for child in node.children if child.type in ["elif_clause", "else_clause"]]
    return exiting_if(node) and len(alternatives) == 1 and alternatives[0].type == "else_clause"


def siblings(node):
    return [child for child in node.parent.children if child.type != "comment"]


def holds_exiting_if(items):
    return any(exiting_if(item) or contains(item, exiting_if) for item in items)


@guard("the only exiting if/else, last in its block, its else-body free of exiting ifs")
def single_exiting_if_else(node):
    if node.parent.type not in ["block", "module"] or not exiting_if_else(node) or not last_in_block(node):
        return False
    clause = [child for child in node.children if child.type == "else_clause"][0]
    body = [child for child in clause.child_by_field_name("body").children if child.type != "comment"]
    if [child.type for child in clause.children if child.type != "comment"] != [
        "else",
        ":",
        "block",
    ] or has_multiline_string(clause):
        return False
    return not any(bare_exiting_if(item) for item in siblings(node)) and not holds_exiting_if(body)


@guard("the only exiting if of its block, followed by a rest free of exiting ifs")
def single_exiting_if_then_rest(node):
    if node.parent.type not in ["block", "module"] or not bare_exiting_if(node):
        return False
    items = siblings(node)
    rest = items[items.index(node) + 1 :]
    return (
        bool(rest)
        and sum(bare_exiting_if(item) for item in items) == 1
        and not holds_exiting_if(rest)
        and not any(has_multiline_string(item) for item in rest)
    )


def drop_else(node, source):
    """if c: ...return x  else: B -> if c: ...return x / B   (B dedented to the if's level)"""
    clause = [child for child in node.children if child.type == "else_clause"][0]
    first, consequence = clause.children[2], node.child_by_field_name("consequence")
    outer, inner = source.leading(node), source.leading(first)
    if outer is None or inner is None or inner != source.leading(consequence) or source.leading(clause) != outer:
        raise Reject("irregular layout")
    return [Edit(clause.start_byte, clause.end_byte, reindent(source, first.start_byte, clause.end_byte, inner, outer))]


def add_else(node, source):
    """if c: ...return x / rest -> if c: ...return x  else: rest   (rest indented like the if-branch)"""
    consequence = node.child_by_field_name("consequence")
    rest_start, rest_end = node.next_named_sibling, node.parent.children[-1]
    outer, inner = source.leading(node), source.leading(consequence)
    if outer is None or inner is None or source.leading(rest_start) != outer:
        raise Reject("irregular layout")
    body = reindent(source, rest_start.start_byte, rest_end.end_byte, outer, inner)
    return [Edit(rest_start.start_byte, rest_end.end_byte, f"else:\n{inner}{body}")]


RANGE_FROM = builtin_call("range", 2).where(
    ~guard("starts at 0")(lambda node: first_argument(node).type == "integer" and first_argument(node).text == b"0")
)
RANGE_STEP = builtin_call("range", 3).where(
    argument_text(2, "1"),
    ~guard("starts at 0")(lambda node: first_argument(node).type == "integer" and first_argument(node).text == b"0"),
)


# ---------------------------------------------------------------- registry

EQUALITY_TEST = COMPARISON.where(operator_in(*EQUALITY), ~in_expanded_comparison, binary)

RULES = {
    "1.1": PRINT_CALL.where(~passes(b"flush", b"True")).rule(add_keyword("flush=True")),
    "1.2": PRINT_CALL.where(passes(b"flush", b"True")).rule(drop_keyword(b"flush")),
    "1.3": PRINT_CALL.where(~passes(b"end")).rule(add_keyword("end='\\n'")),
    "1.4": PRINT_CALL.where(passes(b"end", b'"\\n"', b"'\\n'")).rule(drop_keyword(b"end")),
    "2.1": nodes("list").where(child_count(2)).rule(lambda node, source: [replace(node, "list()")]),
    "2.2": call_to("list", 2).rule(lambda node, source: [replace(node, "[]")]),
    "2.3": nodes("list").where(not_argument_of(b"list")).rule(wrap_in("list")),
    "2.4": call_to("list", 3).where(first_argument_is("list")).rule(unwrap_call),
    "3.1": nodes("dictionary").where(child_count(2)).rule(lambda node, source: [replace(node, "dict()")]),
    "3.2": call_to("dict", 2).rule(lambda node, source: [replace(node, "{}")]),
    "3.3": nodes("dictionary")
    .where(not_argument_of(b"dict"), guard("non-empty")(lambda node: len(node.children) > 2))
    .rule(wrap_in("dict")),
    "3.4": call_to("dict", 3).where(first_argument_is("dictionary", nonempty=True)).rule(unwrap_call),
    "4.1": call_to("range", 3).rule(add_range_start),
    "4.2": call_to("range", 5).where(zero_start).rule(del_range_start),
    "4.3": SLICE.rule(add_slice_index),
    "4.4": SLICE.rule(del_slice_index),
    "6.1": nodes("string").rule(requote("'", '"')),
    "6.2": nodes("string").rule(requote('"', "'")),
    "6.3": nodes("string").where(literal_without_interpolation(False)).rule(set_prefix(lambda start: "f" + start)),
    "6.4": nodes("string")
    .where(literal_without_interpolation(True))
    .rule(set_prefix(lambda start: start.replace("f", ""))),
    "7.1": SELF_ASSIGNMENT.where(numeric_variable).rule(to_augmented),
    "7.2": nodes("augmented_assignment").where(binary, numeric_variable).rule(from_augmented),
    "7.3": EQUALITY_TEST.where(~negated, boolean_context).rule(negate_equality("==", "!=")),
    "7.4": negated_test("!=").where(boolean_context).rule(remove_negation("==")),
    "7.5": EQUALITY_TEST.where(~negated, boolean_context).rule(negate_equality("!=", "==")),
    "7.6": negated_test("==").where(boolean_context).rule(remove_negation("!=")),
    "7.7": COMPARISON.where(operator_in(*RELATIONAL), binary).rule(mirror([">", ">="])),
    "7.8": COMPARISON.where(operator_in(*RELATIONAL), binary).rule(mirror(["<", "<="])),
    "7.9": COMPARISON.where(operator_in(*RELATIONAL), ~in_expanded_comparison, binary)
    .where(boolean_context, pure_comparison)
    .rule(expand_comparison),
    "7.10": nodes("parenthesized_expression")
    .where(expanded_comparison)
    .where(boolean_context, pure_comparison)
    .rule(contract_comparison),
    "7.11": EQUALITY_TEST.rule(hash_order("==", "!=", True)),
    "7.12": EQUALITY_TEST.rule(hash_order("==", "!=", False)),
    "7.13": EQUALITY_TEST.rule(hash_order("!=", "==", True)),
    "7.14": EQUALITY_TEST.rule(hash_order("!=", "==", False)),
    "9.1": tuple_assignment(False).rule(split_assignment),
    "9.2": tuple_assignment(True).rule(chain_assignment),
    "10.1": returns("expression_list").rule(
        lambda node, source: [insert_before(node.children[1], "("), insert_after(node.children[1], ")")]
    ),
    "10.2": returns("tuple").rule(strip_parentheses),
    "10.3": RETURN.where(child_count(1)).rule(lambda node, source: [insert_after(node, " None")]),
    "10.4": RETURN.where(child_count(2), guard("returns None")(lambda node: node.children[1].type == "none")).rule(
        lambda node, source: [delete_between(node.children[0].end_byte, node.children[1].end_byte)]
    ),
    "14.1": negated_comparison("in").where(well_formed).rule(sink_not("not in")),
    "14.2": two_word_test("not", "in").where(well_formed).rule(lift_not("in")),
    "15.1": negated_comparison("is").where(well_formed).rule(sink_not("is not")),
    "15.2": two_word_test("is", "not").where(well_formed).rule(lift_not("is")),
    "16.1": if_else(negated_form=True).where(well_formed).rule(swap_branches(negate=False)),
    "16.2": if_else(negated_form=False).where(well_formed).rule(swap_branches(negate=True)),
    "17.1": conditional(negated_form=True).where(well_formed).rule(swap_conditional(negate=False)),
    "17.2": conditional(negated_form=False).where(well_formed).rule(swap_conditional(negate=True)),
    "18.1": builtin_call("sum", 2).where(argument_text(1, "0")).where(well_formed).rule(drop_last_argument),
    "18.2": builtin_call("sum", 1).where(well_formed).rule(append_argument(0)),
    "19.1": RANGE_STEP.where(well_formed).rule(drop_last_argument),
    "19.2": RANGE_FROM.where(well_formed).rule(append_argument(1)),
    "20.1": nodes("while_statement")
    .where(guard("while True opened by if not C: break")(while_true_with_break))
    .where(well_formed)
    .rule(from_while_true),
    "20.2": nodes("while_statement")
    .where(guard("while C with a negatable C")(plain_while))
    .where(well_formed)
    .rule(to_while_true),
    "21.1": nodes("if_statement").where(single_exiting_if_then_rest).where(well_formed).rule(add_else),
    "21.2": nodes("if_statement").where(single_exiting_if_else).where(well_formed).rule(drop_else),
}


# ---------------------------------------------------------------- extension rules (rule set "extended")
#
# Exact inverses that create or remove no candidate of a legacy pair: comparison operands (equality negation, hash
# order, expcmp, membership/identity), `a = a <op> b` (7.x), tuple and None returns (10.x), negated and compound
# conditions (16.x, expcmp) and while loops (20.x) are left alone. All forms stay on one line.


@guard("outside comparison operands")
def outside_comparisons(node):
    parent = node.parent
    while parent is not None and not parent.type.endswith(("statement", "block", "clause")):
        if parent.type == "comparison_operator":
            return False
        parent = parent.parent
    return True


def single_line(node):
    return b"\n" not in node.text


def keyword_value(node, field=None):
    """The value after the statement keyword when separated from it by exactly one space, else None."""
    if field is not None:
        value = node.child_by_field_name(field)
    else:
        values = [child for child in node.named_children if child.type != "comment"]
        value = values[0] if len(values) == 1 and len(values) == len(node.named_children) else None
    if value is None:
        return None
    keyword = node.children[0]
    gap = node.text[keyword.end_byte - node.start_byte : value.start_byte - node.start_byte]
    return value if gap == b" " and single_line(value) else None


# and/or values too: expcmp (7.10) reads `(a < b or a == b)` with its parentheses.
NOT_PARENTHESIZED_RETURN = [
    "parenthesized_expression",
    "tuple",
    "expression_list",
    "none",
    "yield",
    "named_expression",
    "boolean_operator",
]


@guard("return E on one line, E not parenthesized, a tuple, None or yield")
def plain_return(node):
    value = keyword_value(node)
    return value is not None and value.type not in NOT_PARENTHESIZED_RETURN


def directly_parenthesized(value, excluded):
    if value is None or value.type != "parenthesized_expression" or len(value.children) != 3:
        return False
    inner = value.children[1]
    return inner.type not in excluded and value.text == b"(" + inner.text + b")"


@guard("return (E) with the parentheses directly around E, E not a tuple, None or yield")
def parenthesized_return(node):
    return directly_parenthesized(keyword_value(node), NOT_PARENTHESIZED_RETURN)


def add_parentheses_to(field=None):
    def rewrite(node, source):
        value = keyword_value(node, field)
        return [insert_before(value, "("), insert_after(value, ")")]

    return rewrite


def drop_parentheses_of(field=None):
    def rewrite(node, source):
        value = keyword_value(node, field)
        return [delete(value.children[0]), delete(value.children[2])]

    return rewrite


LITERAL_OPERANDS = ["integer", "float"]


def holds_operation(node):
    """An operation inside the operand, which could be a candidate of its own: one rewrite pass would then edit
    nested text twice (`dp[i + 1] + 2`), so neither is taken."""
    stack = list(node.children)
    while stack:
        current = stack.pop()
        if current.type == "binary_operator":
            return True
        stack.extend(current.children)
    return False


PLAIN_OPERANDS = ["identifier", "call", "subscript", "attribute", "parenthesized_expression"]


def literal_operation(literal_left):
    def test(node):
        if len(node.children) != 3 or text(node.children[1]) not in ["+", "*"]:
            return False
        literal, other = (node.children[0], node.children[2]) if literal_left else (node.children[2], node.children[0])
        if literal.type not in LITERAL_OPERANDS or other.type not in PLAIN_OPERANDS or holds_operation(other):
            return False
        parent = node.parent
        return not (
            parent is not None
            and parent.type == "assignment"
            and parent.child_by_field_name("left") is not None
            and text(parent.child_by_field_name("left")).strip() == text(other).strip()
        )

    side = "literal first" if literal_left else "literal last"
    return guard(f"{side} in + or * with a plain other operand (not a self-assignment)")(test)


def swap_operands(node, source):
    """x + 1 -> 1 + x (and back): the operands trade places, the operator and spacing stay."""
    left, right = node.children[0], node.children[2]
    return [replace(left, text(right)), replace(right, text(left))]


NOT_PARENTHESIZED_CONDITION = [
    "parenthesized_expression",
    "not_operator",
    "boolean_operator",
    "tuple",
    "generator_expression",
    "yield",
]
CONDITIONS = Matcher("[(if_statement) (elif_clause)] @node")


def without_else(node):
    """Not an if/else: branch order (16.x) takes `if <primary>: A else: B` only without parentheses."""
    return node.type != "if_statement" or not any(child.type == "else_clause" for child in node.children)


@guard("if/elif C on one line, C not parenthesized, negated or compound, no if/else")
def plain_condition(node):
    value = keyword_value(node, "condition")
    return without_else(node) and value is not None and value.type not in NOT_PARENTHESIZED_CONDITION


@guard("if/elif (C) with the parentheses directly around C, C not negated or compound, no if/else")
def parenthesized_condition(node):
    return without_else(node) and directly_parenthesized(keyword_value(node, "condition"), NOT_PARENTHESIZED_CONDITION)


COLLECTIONS = Matcher("[(list) (dictionary) (set)] @node")


def collection_elements(node):
    return [child for child in node.children[1:-1] if child.type != ","]


@guard("non-empty one-line literal without trailing comma or comments")
def without_trailing_comma(node):
    elements = collection_elements(node)
    return (
        single_line(node)
        and bool(elements)
        and all(element.type != "comment" for element in elements)
        and node.children[-2].type != ","
    )


@guard("one-line literal ending with a comma directly after the last element and before the bracket")
def with_trailing_comma(node):
    elements = collection_elements(node)
    comma = node.children[-2]
    return (
        single_line(node)
        and bool(elements)
        and all(element.type != "comment" for element in elements)
        and comma.type == ","
        and len(node.children) >= 4
        and node.children[-3].end_byte == comma.start_byte
        and comma.end_byte == node.children[-1].start_byte
    )


ASSIGNED_OPERATIONS = ["binary_operator"]


def assigned_value(node):
    """The value of `target = value` (one space after `=`, value on one line), else None."""
    value = node.child_by_field_name("right")
    if value is None or len(node.children) != 3 or node.children[1].type != "=":
        return None
    gap = node.text[node.children[1].end_byte - node.start_byte : value.start_byte - node.start_byte]
    return value if gap == b" " and single_line(value) else None


def assigned_operation(node, value):
    """`value` (or the expression inside it) when it is an operation that neither operand of repeats the target."""
    if value is None or value.type not in ASSIGNED_OPERATIONS:
        return None
    target = text(node.child_by_field_name("left")).strip()
    operands = [value.child_by_field_name("left"), value.child_by_field_name("right")]
    return None if any(operand is None or text(operand).strip() == target for operand in operands) else value


@guard("x = a <op> b on one line, an arithmetic or bitwise operation not repeating x (7.x reads a = a <op> b)")
def plain_assigned_operation(node):
    return assigned_operation(node, assigned_value(node)) is not None


@guard("x = (a <op> b) with the parentheses directly around the operation")
def parenthesized_assigned_operation(node):
    value = assigned_value(node)
    return directly_parenthesized(value, []) and assigned_operation(node, value.children[1]) is not None


EXTENSION_RULES = {
    "40.1": RETURN.where(parenthesized_return).where(well_formed).rule(drop_parentheses_of()),
    "40.2": RETURN.where(plain_return).where(well_formed).rule(add_parentheses_to()),
    "41.1": nodes("binary_operator")
    .where(literal_operation(True), outside_comparisons)
    .where(well_formed)
    .rule(swap_operands),
    "41.2": nodes("binary_operator")
    .where(literal_operation(False), outside_comparisons)
    .where(well_formed)
    .rule(swap_operands),
    "42.1": CONDITIONS.where(parenthesized_condition).where(well_formed).rule(drop_parentheses_of("condition")),
    "42.2": CONDITIONS.where(plain_condition).where(well_formed).rule(add_parentheses_to("condition")),
    "43.1": COLLECTIONS.where(with_trailing_comma)
    .where(well_formed)
    .rule(lambda node, source: [delete(node.children[-2])]),
    "43.2": COLLECTIONS.where(without_trailing_comma)
    .where(well_formed)
    .rule(lambda node, source: [insert_after(collection_elements(node)[-1], ",")]),
    "45.1": nodes("assignment")
    .where(parenthesized_assigned_operation)
    .where(well_formed)
    .rule(lambda node, source: [delete(assigned_value(node).children[0]), delete(assigned_value(node).children[2])]),
    "45.2": nodes("assignment")
    .where(plain_assigned_operation)
    .where(well_formed)
    .rule(lambda node, source: [insert_before(assigned_value(node), "("), insert_after(assigned_value(node), ")")]),
}

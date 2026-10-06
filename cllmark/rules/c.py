"""C rewrite rules (style ids as in styles.json); C++ builds on them in cpp.py.

Ported from the original operators: candidate conditions and generated text are kept,
including known semantic hazards of the original method (documented on each rule), so
watermark results stay comparable. Edits are node-anchored; new lines take the
indentation width the original rules computed (spaces, tab = 4 columns).
"""

import hashlib
import re

from .braces import add_braces, bare_layout, braced_layout, drop_braces
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


def nodes(node_type):
    return Matcher(f"(({node_type}) @node)")


def child_count(count):
    return guard(f"{count} children")(lambda node: len(node.children) == count)


def contain_id(node, contain):
    """Identifiers in the subtree (pre-order, as the original helper; insertion order matters for list(set)[0])."""
    if node.child_by_field_name("index"):
        contain.add(text(node.child_by_field_name("index")))
    if node.type == "identifier" and node.parent.type not in ["subscript_expression", "call_expression"]:
        contain.add(text(node))
    for child in node.children:
        contain_id(child, contain)


def blank_run_start(source, position):
    """Start of the spaces/tabs directly before `position`."""
    start = position
    while start > 0 and source.data[start - 1 : start] in (b" ", b"\t"):
        start -= 1
    return start


# ---------------------------------------------------------------- comparisons and assignments

RELATIONAL = [">", ">=", "<", "<="]
EQUALITY = ["==", "!="]
BINARY = nodes("binary_expression")
binary = child_count(3)


def operator_in(*operators):
    return guard("operator " + "|".join(operators))(lambda node: text(node.children[1]) in operators)


def operands(node):
    return [text(child) for child in node.children]


@guard("directly inside !(...)")
def negated(node):
    parent = node.parent
    return (
        parent is not None
        and parent.type == "parenthesized_expression"
        and len(parent.children) == 3
        and parent.parent is not None
        and parent.parent.type == "unary_expression"
        and text(parent.parent.children[0]) == "!"
    )


@guard("operand of a parenthesized expanded comparison")
def in_expanded_comparison(node):
    """Part of `(a < b || a == b)`; such tests belong to the expcmp/cmp rules."""
    junction = node.parent
    if (
        junction is None
        or junction.type != "binary_expression"
        or len(junction.children) != 3
        or text(junction.children[1]) not in ["&&", "||"]
        or junction.parent is None
        or junction.parent.type != "parenthesized_expression"
    ):
        return False
    first, second = junction.children[0], junction.children[2]
    return (
        first.type == "binary_expression"
        and second.type == "binary_expression"
        and text(first.children[1]) in RELATIONAL
        and text(second.children[1]) in EQUALITY
        and {text(first.children[0]).strip(), text(first.children[2]).strip()}
        == {text(second.children[0]).strip(), text(second.children[2]).strip()}
    )


@guard("(a < b || a == b) with simple comparisons")
def expanded_comparison(node):
    if len(node.children) != 3:
        return False
    junction = node.children[1]
    if (
        junction.type != "binary_expression"
        or len(junction.children) != 3
        or text(junction.children[1]) not in ["&&", "||"]
    ):
        return False
    first, second = junction.children[0], junction.children[2]
    return (
        first.type == "binary_expression"
        and second.type == "binary_expression"
        and len(first.children) == 3
        and len(second.children) == 3
        and text(first.children[1]) in RELATIONAL
        and text(second.children[1]) in EQUALITY
        and {text(first.children[0]).strip(), text(first.children[2]).strip()}
        == {text(second.children[0]).strip(), text(second.children[2]).strip()}
    )


def negate_equality(operator, inverse):
    """a == b -> ! (a != b)"""

    def rewrite(node, source):
        a, current, b = operands(node)
        if current != operator:
            raise Reject("other operator")
        return [replace(node, f"! ({a} {inverse} {b})")]

    return rewrite


def negated_test(inner):
    """!(a <inner> b)"""

    def test(node):
        if len(node.children) != 2 or text(node.children[0]) != "!":
            return False
        group = node.children[1]
        if group.type != "parenthesized_expression" or len(group.children) != 3:
            return False
        comparison = group.children[1]
        return (
            comparison.type == "binary_expression"
            and len(comparison.children) == 3
            and text(comparison.children[1]) == inner
        )

    return nodes("unary_expression").where(guard(f"!(a {inner} b)")(test))


def remove_negation(operator):
    def rewrite(node, source):
        a, _, b = operands(node.children[1].children[1])
        return [replace(node, f"{a} {operator} {b}")]

    return rewrite


def mirror(flipped):
    """a > b -> b < a"""
    return lambda node, source: [replace(node, f"{operands(node)[2]} {flipped[operands(node)[1]]} {operands(node)[0]}")]


EXPAND = {
    "<=": "({a} < {b} || {a} == {b})",
    "<": "({a} <= {b} && {a} != {b})",
    ">=": "({a} > {b} || {a} == {b})",
    ">": "({a} >= {b} && {a} != {b})",
}
CONTRACT = {">": ">=", "<": "<=", ">=": ">", "<=": "<"}


def expand_comparison(node, source):
    """a <= b -> (a < b || a == b)"""
    a, operator, b = operands(node)
    return [replace(node, EXPAND[operator].format(a=a, b=b))]


def contract_comparison(node, source):
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


ARITHMETIC = ["+", "-", "*", "/", "%", "<<", ">>"]
COMPOUND = ["+=", "-=", "*=", "/=", "%=", "<<=", ">>="]


@guard("a = a <op> b")
def self_assignment(node):
    if len(node.children) != 3 or text(node.children[1]) != "=":
        return False
    right = node.children[2]
    return (
        right.type == "binary_expression"
        and len(right.children) == 3
        and text(right.children[1]) in ARITHMETIC
        and text(node.children[0]).strip() == text(right.children[0]).strip()
    )


def to_compound(node, source):
    """a = a + b -> a += b"""
    right = node.children[2]
    return [replace(node, f"{text(node.children[0])} {text(right.children[1])}= {text(right.children[2])}")]


BINDING = {
    "*": 10,
    "/": 10,
    "%": 10,
    "+": 9,
    "-": 9,
    "<<": 8,
    ">>": 8,
    "<": 7,
    "<=": 7,
    ">": 7,
    ">=": 7,
    "==": 6,
    "!=": 6,
    "&": 5,
    "^": 4,
    "|": 3,
    "&&": 2,
    "||": 1,
}
LOOSE = ["conditional_expression", "assignment_expression", "comma_expression"]


def from_compound(node, source):
    """a += b -> a = a + b, only when b binds tighter than the operator (a *= b + c would become a * b + c)."""
    if len(node.children) != 3:
        raise Reject("malformed assignment")
    a, operator, b = operands(node)
    value = node.children[2]
    if value.type in LOOSE or (
        value.type == "binary_expression" and BINDING.get(text(value.children[1]), 0) <= BINDING[operator[:-1]]
    ):
        raise Reject("right side binds more loosely than the operator")
    return [replace(node, f"{a} = {a} {operator[:-1]} {b}")]


# ---------------------------------------------------------------- ++i / i++


@guard("statement-level ++/--")
def update_outside_index_call_assignment(node):
    """The value of i++ / ++i is unused: an expression statement, a for update, or a comma list in those."""
    if node.parent.type in [
        "subscript_expression",
        "subscript_argument_list",
        "assignment_expression",
        "argument_list",
    ]:
        return False
    parent, child = node.parent, node
    while parent.type == "comma_expression":
        parent, child = parent.parent, parent
    return parent.type == "expression_statement" or (
        parent.type == "for_statement"
        and child.prev_sibling is not None
        and child.next_sibling is not None
        and child.next_sibling.type == ")"
    )


def update_operand_at(index):
    return guard(f"operand is child {index}")(lambda node: node.children[index].type == "identifier")


def to_prefix(node, source):
    """i++ -> ++i"""
    return [delete(node.children[1]), insert_before(node, text(node.children[1]))]


def to_postfix(node, source):
    """++i -> i++"""
    return [delete(node.children[0]), insert_after(node, text(node.children[0]))]


# ---------------------------------------------------------------- main()

MAIN = nodes("function_definition").where(
    guard("main definition")(
        lambda node: node.children[1].type == "function_declarator" and node.children[1].children[0].text == b"main"
    )
)
PARAMETERS = {
    "void": ("(void)", lambda params: params.child_count == 3 and "void" in text(params)),
    "none": ("()", lambda params: params.child_count == 2),
    "args": ("(int argc, char *argv[])", lambda params: params.child_count == 5 and "arg" in text(params)),
}


def identifier_names(node):
    names, stack = set(), [node]
    while stack:
        current = stack.pop()
        if current.type == "identifier":
            names.add(text(current))
        stack.extend(current.children)
    return names


def main_signature(return_type, parameters, with_return):
    """Normalise main's return type and parameters; add `return 0;` or remove the final return."""
    new_parameters, accepted = PARAMETERS[parameters]

    def rewrite(node, source):
        returned, params, body = node.children[0], node.children[1].children[1], node.children[2]
        last_return = None
        for statement in body.children:
            if statement.type == "return_statement":
                last_return = statement
        edits = []
        if text(returned) != return_type:
            edits.append(replace(returned, return_type))
        if not accepted(params):
            # The parameters a new signature drops must be unused, and the names it adds unused too (main's
            # parameters share the scope of its outermost block): `main(int argc, char *argv[])` -> `main(void)` with
            # argv read in the body does not compile.
            old, new = identifier_names(params), {"argc", "argv"} if parameters == "args" else set()
            if (old ^ new) & identifier_names(body):
                raise Reject("main's body uses a parameter name the new signature drops or adds")
            edits.append(replace(params, new_parameters))
        if with_return and last_return is None and len(body.children) > 1:
            edits.append(insert_after(body.children[-2], "\n    return 0;"))
        if not with_return and last_return is not None:
            edits.append(delete(last_return))
        return edits

    return rewrite


# ---------------------------------------------------------------- arrays and pointers (C)


def array_dimension(node):
    dimension = 0
    while node.child_count:
        node = node.children[0]
        dimension += 1
    return dimension


def pointer_dimension(node):
    count, stack = 0, [node]
    while stack:
        current = stack.pop()
        count += current.type == "pointer_expression"
        stack.extend(current.children)
    return count


def nested_brackets(node):
    """a[b[i]]: a '[' opens while another is open (the original scan, which raises on a stray ']')."""
    stack = []
    for character in text(node):
        if character == "[":
            if stack:
                return True
            stack.append(character)
        elif character == "]":
            stack.pop()
    return False


def malloc_declarator(node):
    """type *a = (type *)malloc(...)"""
    if (
        node.type != "init_declarator"
        or len(node.children) != 3
        or node.children[0].type != "pointer_declarator"
        or node.children[0].children[1].type == "pointer_declarator"
        or text(node.children[1]).strip() != "="
        or node.children[2].type != "cast_expression"
    ):
        return False
    call = node.children[2].children[-1]
    return call.type == "call_expression" and bool(call.children[0]) and text(call.children[0]) == "malloc"


def split_top_level_stars(value):
    """Split a size expression at '*' outside parentheses, keeping the '*' separators."""
    result, buffer, depth = [], [], 0
    for character in value:
        if character == "(":
            depth += 1
            buffer.append(character)
        elif character == ")":
            depth = max(depth - 1, 0)
            buffer.append(character)
        elif character == "*" and not depth:
            if buffer:
                result.append("".join(buffer))
                buffer = []
            result.append("*")
        else:
            buffer.append(character)
    if buffer:
        result.append("".join(buffer))
    return result


def strip_outer_parentheses(value):
    while value and value[0] == "(" and value[-1] == ")":
        depth = 0
        for index, character in enumerate(value):
            if character == "(":
                depth += 1
            elif character == ")":
                depth -= 1
                if depth == 0 and index != len(value) - 1:
                    return value
        value = value[1:-1]
    return value


def element_count(size_expression):
    """`sizeof(int) * n` -> `n`: drop sizeof factors (and the '*' next to them)."""
    parts = split_top_level_stars(size_expression)
    for index in range(len(parts)):
        if "sizeof" in parts[index]:
            if index != len(parts) - 1:
                parts[index] = parts[index + 1] = ""
            else:
                parts[-1] = parts[-2] = ""
    return strip_outer_parentheses("".join(parts).strip())


def enclosing_function_body(node):
    current = node.parent
    while current is not None and current.type != "function_definition":
        current = current.parent
    return None if current is None else current.child_by_field_name("body")


def name_uses(scope, name):
    """The identifier nodes spelling `name` inside `scope`."""
    found, stack = [], [scope]
    while stack:
        current = stack.pop()
        if current.type == "identifier" and current.text == name:
            found.append(current)
        stack.extend(current.children)
    return found


def lifetime_bound(use):
    """A use that depends on the object outliving its block or being heap memory: freed, reallocated, returned or
    assigned a new address."""
    parent = use.parent
    if parent.type == "argument_list":
        call = parent.parent
        return call.type == "call_expression" and text(call.children[0]) in ["free", "realloc"]
    if parent.type == "return_statement":
        return True
    return parent.type == "assignment_expression" and parent.children[0] == use


def size_bound(use):
    """A use whose meaning depends on the object being an array: sizeof a, &a."""
    parent = use.parent
    while parent is not None and parent.type == "parenthesized_expression":
        parent = parent.parent
    return parent is not None and (
        parent.type == "sizeof_expression" or (parent.type == "pointer_expression" and text(parent.children[0]) == "&")
    )


@guard("a local array used neither in sizeof nor with &, not static or extern (malloc would change its meaning)")
def movable_array(node):
    body = enclosing_function_body(node)
    if body is None or any(child.type == "storage_class_specifier" for child in node.children):
        return False
    for child in node.children:
        if child.type == "array_declarator" and any(size_bound(use) for use in name_uses(body, child.children[0].text)):
            return False
    return True


@guard("a local malloc'd pointer that is never freed, reallocated, returned or reassigned (an array would not be)")
def movable_allocation(node):
    body = enclosing_function_body(node)
    if body is None:
        return False
    for child in node.children:
        if malloc_declarator(child):
            pointer = child.children[0]
            if len(pointer.children) != 2 or pointer.children[1].type != "identifier":
                return False  # `T *const p`: qualified pointers keep no array spelling
            if any(lifetime_bound(use) for use in name_uses(body, pointer.children[1].text)):
                return False
    return True


@guard("declares an array of at most two dimensions")
def static_array_declaration(node):
    dimensions = [array_dimension(child) for child in node.children if child.type == "array_declarator"]
    return bool(dimensions) and min(dimensions) <= 2


def static_to_dynamic(node, source):
    """type a[n] -> type *a = (type*)malloc(sizeof(type) * n)"""
    element = text(node.child_by_field_name("type"))
    edits = []
    for child in node.children:
        if child.type == "struct_specifier" and child.child_by_field_name("body"):
            raise Reject("declares a struct type")
        if child.type == "array_declarator":
            if child.children[0].type != "identifier":
                raise Reject("multi-dimensional array")
            size = child.children[2]
            count = f"({text(size)})" if size.child_count > 1 else text(size)
            edits.append(
                replace(child, f"*{text(child.children[0])} = ({element}*)malloc(sizeof({element}) * {count})")
            )
    return edits


def dynamic_to_static(node, source):
    """type *a = (type*)malloc(sizeof(type) * n) -> type a[n]"""
    edits = []
    for declarator in node.children:
        if not malloc_declarator(declarator):
            continue
        pointer = declarator.children[0]
        call = declarator.children[2].children[-1]
        arguments = call.children[-1]
        if arguments.type != "argument_list":
            continue
        if arguments.children[1].type == "sizeof_expression":
            raise Reject("allocation size is a bare sizeof")
        if len(arguments.children) == 3:
            name_end = pointer.children[1].end_byte
            edits += [
                delete(pointer.children[0]),
                Edit(name_end, declarator.end_byte, f"[{element_count(text(arguments.children[1]))}]"),
            ]
    return edits


@guard("a[i] outside nested subscripts and member access")
def plain_subscript(node):
    return node.parent.type not in ["subscript_expression", "pointer_expression", "comma_expression"] and node.children[
        0
    ].type not in ["call_expression", "field_expression", "parenthesized_expression"]


POINTER_ARITHMETIC = re.compile(r"\*\([^\+]+\+[^\)]+\)")


def array_to_pointer(node, source):
    """a[i] -> *(a + i);  a[i][j] -> *(*(a + i) + j);  a[i][j][k] likewise

    One dimension reads the `index` field, more dimensions the third child of each level
    (they differ only in error-recovered trees), as the original operator did.
    """
    dimension = array_dimension(node)
    if dimension == 1:
        return [replace(node, f"*({text(node.children[0])} + {text(node.child_by_field_name('index'))})")]
    subscripts, base = [], node
    for _ in range(dimension):
        if len(base.children) < 3:
            raise Reject("irregular subscript")
        subscripts.insert(0, text(base.children[2]))
        base = base.children[0]
    expression = text(base)
    for index in subscripts:
        expression = f"*({expression} + {index})"
    return [replace(node, expression)]


def leftmost_identifier(node):
    while node:
        if node.type == "binary_expression":
            node = node.child_by_field_name("left")
        elif node.type == "identifier":
            return node
        else:
            return None


def after_operator(source, identifier, expression):
    """Text of `expression` after the operator that follows `identifier` (the original index extraction)."""
    if identifier is None or identifier.next_sibling is None:
        raise Reject("pointer base is not a plain identifier")
    return source.data[identifier.next_sibling.end_byte : expression.end_byte].decode("utf-8")


def inner_index(binary_expression, label):
    """Peel `*(...) + k` (or `k + *(...)`): returns (expression inside the inner parentheses, k text)."""
    left = binary_expression.child_by_field_name("left")
    right = binary_expression.child_by_field_name("right")
    if not left or not right:
        raise Reject("incomplete expression")
    if left.type == "pointer_expression" and right.type in ["number_literal", "identifier"]:
        inner, offset = left, right
    elif right.type == "pointer_expression" and left.type in ["number_literal", "identifier"]:
        inner, offset = right, left
    else:
        raise Reject("unsupported " + label)
    argument = inner.child_by_field_name("argument")
    if argument.child_count < 2:
        raise Reject("pointer without parentheses")
    return argument.children[1], text(offset)


def pointer_to_array(node, source):
    """*(a + i) -> a[i];  *(*(a + i) + j) -> a[i][j];  three levels likewise"""
    dimension = pointer_dimension(node)
    argument = node.child_by_field_name("argument")
    if dimension == 1:
        if argument.child_count == 0:
            raise Reject("*p")
        expression = argument.children[1]
        base = leftmost_identifier(expression)
        index = after_operator(source, base, expression)
        return [replace(node, f"{text(base)}[{index.strip()}]")]
    expression = argument.children[1]
    if dimension == 2:
        expression, second = inner_index(expression, "second index")
        base = leftmost_identifier(expression)
        first = after_operator(source, base, expression)
        return [replace(node, f"{text(base)}[{first.strip()}][{second.strip()}]")]
    if dimension == 3:
        expression, third = inner_index(expression, "third index")
        expression, second = inner_index(expression, "second index")
        first = text(expression.child_by_field_name("right"))
        return [
            replace(
                node,
                f"{text(expression.child_by_field_name('left'))}[{first.strip()}][{second.strip()}][{third.strip()}]",
            )
        ]
    raise Reject("deeper pointer expression")


@guard("outermost *(a + i)")
def outermost_pointer_arithmetic(node):
    argument = node.children[1] if len(node.children) > 1 else None
    if (
        "&" in text(node)
        or not argument
        or argument.type != "parenthesized_expression"
        or argument.children[1].type != "binary_expression"
    ):
        return False
    dimension = pointer_dimension(node)
    parent = node.parent
    while parent is not None:
        if parent.type == "pointer_expression":
            return False
        parent = parent.parent
    return dimension < 4


# ---------------------------------------------------------------- declarations

NEGLECTED = [
    ",",
    ";",
    "subscript_expression",
    "call_expression",
    "primitive_type",
    "sized_type_specifier",
    "struct_specifier",
    "storage_class_specifier",
]


def declared_type(node):
    """Declaration type with every static/const specifier prefixed (as the original get_type)."""
    prefix = "".join(
        "static " if child.type == "storage_class_specifier" else "const " if child.type == "type_qualifier" else ""
        for child in node.children
    )
    return prefix + text(node.child_by_field_name("type"))


@guard("declares more than one name")
def multi_name_declaration(node):
    if node.children[0].type in ["storage_class_specifier", "type_qualifier"] or node.parent.type == "for_statement":
        return False
    names = set()
    contain_id(node, names)
    return len(names) > 1


def split_declaration(node, source):
    """int a, b; -> int a; / int b; (one line each; a struct/union/enum definition is never duplicated)"""
    # The declarator field, not every child after the first: `size_t const a = 1;` has a qualifier after its type.
    declarators = node.children_by_field_name("declarator")
    if len(declarators) < 2:
        raise Reject("single declarator")
    if any(child.type == "ERROR" for child in node.children):
        raise Reject("misparsed declaration")
    kind = node.child_by_field_name("type")
    if kind.type in [
        "struct_specifier",
        "union_specifier",
        "enum_specifier",
        "class_specifier",
    ] and kind.child_by_field_name("body"):
        raise Reject("type definition")
    kind, indent = declared_type(node), source.indent(node.start_byte)
    lines = "".join(f"{indent * ' '}{kind} {text(child)};\n" for child in declarators)
    return [
        Edit(blank_run_start(source, node.start_byte), blank_run_start(source, node.start_byte), lines),
        delete(node),
    ]


@guard("two declarations of one type")
def repeated_declaration_type(node):
    seen = set()
    for child in node.children:
        if child.type == "declaration":
            kind = declared_type(child)
            if kind in seen:
                return True
            seen.add(kind)
    return False


CONSTANT = ["number_literal", "char_literal", "string_literal", "true", "false", "null", "nullptr"]

# Initialiser syntax with no side effects and no dependence on anything but the values of its identifiers;
# a later declaration made of these (and nothing else) can be hoisted over statements that leave those values alone.
HOISTABLE = [
    *CONSTANT,
    "identifier",
    "character",
    "string_content",
    "escape_sequence",
    "parenthesized_expression",
    "unary_expression",
    "binary_expression",
    "cast_expression",
    "type_descriptor",
    "primitive_type",
    "sized_type_specifier",
    "sizeof_expression",
    "concatenated_string",
]
HOISTABLE_UNARY = ["-", "+", "!", "~"]
HOISTABLE_BINARY = [
    "+",
    "-",
    "*",
    "<",
    ">",
    "<=",
    ">=",
    "==",
    "!=",
    "&&",
    "||",
    "&",
    "|",
    "^",
]  # not / % << >> (UB, traps)
DECLARATOR_SYNTAX = [
    "pointer_declarator",
    "array_declarator",
    "parenthesized_declarator",
    "reference_declarator",
    "type_qualifier",
]
JUMP_TARGETS = ["labeled_statement", "case_statement", "goto_statement"]
WRITE_TARGETS = ["pointer_expression", "subscript_expression", "field_expression"]


def subtree(node):
    """The node and all its descendants."""
    stack = [node]
    while stack:
        current = stack.pop()
        yield current
        stack.extend(current.children)


def unparenthesized(node):
    while node is not None and node.type == "parenthesized_expression" and len(node.children) == 3:
        node = node.children[1]
    return node


def impure_syntax(node, allowed):
    """Why `node` is not a side-effect-free expression made of `allowed` syntax (None when it is)."""
    for current in subtree(node):
        if not current.is_named or current.type == "comment":
            continue
        if current.type not in allowed:
            return f"{current.type} in an initialiser or declarator"
        operator = current.child_by_field_name("operator")
        if current.type == "unary_expression" and (operator is None or text(operator) not in HOISTABLE_UNARY):
            return "unary operator " + (text(operator) if operator is not None else "?")
        if current.type == "binary_expression" and (operator is None or text(operator) not in HOISTABLE_BINARY):
            return "binary operator " + (text(operator) if operator is not None else "?")
    return None


def written_through_memory(node):
    """An assignment or increment whose target is a dereference, element or member (it may alias anything)."""
    for current in subtree(node):
        if current.type == "assignment_expression":
            target = current.child_by_field_name("left")
        elif current.type == "update_expression":
            target = current.child_by_field_name("argument")
        else:
            continue
        target = unparenthesized(target)
        if target is not None and target.type in WRITE_TARGETS:
            return True
    return False


def referenced_names(node):
    """Identifiers declared as references (`T &x`, `T &&x`, `auto &[a, b]`, parameters, range-for variables) anywhere in the file."""
    root = node
    while root.parent is not None:
        root = root.parent
    return {
        text(current)
        for declarator in subtree(root)
        if declarator.type == "reference_declarator"
        for current in subtree(declarator)
        if current.type == "identifier"
    }


def written_names(node):
    """Names assigned or incremented directly (`x = 1`, `x += 1`, `(x)++`)."""
    names = set()
    for current in subtree(node):
        if current.type == "assignment_expression":
            target = current.child_by_field_name("left")
        elif current.type == "update_expression":
            target = current.child_by_field_name("argument")
        else:
            continue
        target = unparenthesized(target)
        if target is not None and target.type == "identifier":
            names.add(text(target))
    return names


def array_sizes(declarator):
    return [
        current.child_by_field_name("size")
        for current in subtree(declarator)
        if current.type == "array_declarator" and current.child_by_field_name("size") is not None
    ]


def hoist_blocker(block, first, declaration, kept):
    """Why `declaration` may not join `first` (None when it may).

    Joining moves the declaration up to `first`, so it hops over the nodes of `block` in between
    (comments and declarations already joined do not count). Without such nodes (`int n = v.size(); int i = 0;`)
    nothing is reordered and any initialiser is fine: a declarator ends in a sequence point, so
    `int a = x, b = y;` initialises like two declarations. Otherwise the hop must be invisible: the
    initialisers and array sizes are side-effect-free expressions over identifiers that the crossed nodes
    never mention, call nothing and write through no pointer, element, member or C++ reference; the declared
    names are not mentioned either; no label, case or goto is crossed (a jump would skip the hoisted
    initialisation) and no syntax error (the tree there cannot be trusted).
    """
    joined = {item.id for item in kept}
    crossed = [
        child
        for child in block.children
        if child.start_byte >= first.end_byte
        and child.end_byte <= declaration.start_byte
        and child.type != "comment"
        and child.id not in joined
    ]
    if not crossed:
        return None
    if block.type != "compound_statement":
        return "a declaration after statements outside a compound statement"
    if any(current.type == "ERROR" for node in crossed for current in subtree(node)):
        return "a syntax error lies between the declarations"
    if any(current.type in JUMP_TARGETS for node in crossed for current in subtree(node)):
        return "a label, case or goto lies between the declarations"
    mentioned = [text(node) for node in crossed]
    names, reads = set(), set()
    for declarator in declaration.children_by_field_name("declarator"):
        value = None
        if declarator.type == "init_declarator":
            value, declarator = declarator.child_by_field_name("value"), declarator.child_by_field_name("declarator")
            if value is None:
                return "initialiser without a value"
            reason = impure_syntax(value, HOISTABLE)
            if reason:
                return reason
            reads.update(text(current) for current in subtree(value) if current.type == "identifier")
        reason = impure_syntax(declarator, HOISTABLE + DECLARATOR_SYNTAX)
        if reason:
            return reason
        for size in array_sizes(declarator):
            reads.update(text(current) for current in subtree(size) if current.type == "identifier")
        contain_id(declarator, names)
    for name in sorted(names | reads):
        if any(re.search(r"\b" + re.escape(name) + r"\b", code) for code in mentioned):
            return f"{name} is mentioned between the declarations"
    if reads:
        if any(current.type == "call_expression" for node in crossed for current in subtree(node)):
            return "a call lies between the declarations and the initialiser reads variables"
        if any(written_through_memory(node) for node in crossed):
            return "a write through a pointer, element or member lies between the declarations and the initialiser reads variables"
        written = set().union(*(written_names(node) for node in crossed))
        if written and written & referenced_names(block):
            return "a write to a reference lies between the declarations and the initialiser reads variables"
    return None


def movable_group(block, group):
    """The declarations that may join the first one (see hoist_blocker)."""
    kept = [group[0]]
    for declaration in group[1:]:
        if hoist_blocker(block, group[0], declaration, kept) is None:
            kept.append(declaration)
    return kept


def declaration_kinds(node):
    """The declarations directly inside `node`, grouped by type text (as merge_declarations merges them)."""
    kinds = {}
    for child in node.children:
        if child.type == "declaration":
            kind = text(child.child_by_field_name("type"))
            if child.children[0].type == "storage_class_specifier":
                kind = "static " + kind
            if child.children[0].type == "type_qualifier":
                kind = "const " + kind
            kinds.setdefault(kind, []).append(child)
    return kinds


def untyped_kind(kind):
    """One `auto` declaration may not mix initialisers of different types, so such kinds are not merged."""
    return re.search(r"\b(auto|decltype)\b", kind) is not None


def mergeable_specifiers(declaration):
    """No syntax error, and at most one of `const` / `static` (the only specifiers `declaration_kinds` keeps):
    `static const int a`, `volatile int a`, `constexpr int a` and `extern int a` would lose or change theirs."""
    specifiers = [
        child for child in declaration.children if child.type in ["type_qualifier", "storage_class_specifier"]
    ]
    return (
        not any(child.type == "ERROR" for child in declaration.children)
        and len(specifiers) <= 1
        and all(text(child) in ["const", "static"] for child in specifiers)
    )


def array_ranks(group):
    """Dimensions of every array declarator in the declarations (an initialised array counts too)."""
    ranks = []
    for declaration in group:
        for declarator in declaration.children_by_field_name("declarator"):
            if declarator.type == "init_declarator":
                declarator = declarator.child_by_field_name("declarator")
            if declarator is not None and declarator.type == "array_declarator":
                ranks.append(array_dimension(declarator))
    return ranks


def merge_declarations(node, source):
    """int a; ... int b; -> int a, b; at the first declaration"""
    edits = []
    for kind, declarations in declaration_kinds(node).items():
        if untyped_kind(kind):
            continue
        group = movable_group(node, declarations)
        ids = [text(each) for declaration in group for each in declaration.children_by_field_name("declarator")]
        if len(ids) < 2:
            continue
        if not kind.strip() or "" in ids or any(not mergeable_specifiers(declaration) for declaration in group):
            continue  # misparsed, or specifiers the kind does not carry: merging would drop or fuse them
        ranks = array_ranks(group)
        if 1 in ranks and max(ranks) > 1:
            continue  # array_init (5.1) rejects a whole declaration holding a multi-dimensional array, hiding its 1-D arrays
        starts = [blank_run_start(source, declaration.start_byte) for declaration in group]
        if source.leading(group[0]) is None:
            indent, starts[0] = 0, group[0].start_byte  # mid-line: keep what precedes it, add no blanks
        else:
            indent = source.indent(group[-1].start_byte)
        edits.append(Edit(starts[0], group[0].end_byte, f"{indent * ' '}{kind} {', '.join(ids)};"))
        edits += [Edit(start, declaration.end_byte) for start, declaration in zip(starts[1:], group[1:], strict=True)]
    return edits


# ---------------------------------------------------------------- for / while loops


def for_parts(node):
    """[init, condition, update, body] of a for statement (None when absent), as the original get_for_info."""
    index, parts = 0, [None, None, None, None]
    for child in node.children:
        if child.type in [";", ")", "declaration"]:
            if child.type == "declaration":
                parts[index] = child
            if child.prev_sibling.type not in ["(", ";", "declaration"]:
                parts[index] = child.prev_sibling
            index += 1
        if child.prev_sibling and child.prev_sibling.type == ")" and index == 3:
            parts[3] = child
    return parts


MARKER = "int identifier = 1"


def is_marker(init):
    return text(init).replace(";", "").strip() == MARKER


def not_equality_test(node):
    """True unless the condition is a == / != test, possibly negated."""
    if node.type == "binary_expression" and len(node.children) == 3 and text(node.children[1]) in EQUALITY:
        return False
    if node.type == "unary_expression" and len(node.children) == 2 and text(node.children[0]) == "!":
        group = node.children[1]
        if group.type == "parenthesized_expression" and len(group.children) == 3:
            inner = group.children[1]
            if inner.type == "binary_expression" and len(inner.children) == 3 and text(inner.children[1]) in EQUALITY:
                return False
    return True


FOR = nodes("for_statement").where(guard("not labelled")(lambda node: node.parent.type != "labeled_statement"))


def hoist_init(node, source, init):
    """a moves before the loop (declarations stay in the header)."""
    if init.type == "declaration":
        return []
    return [delete(init), insert_before(node, text(init) + ";\n" + source.indent(node.start_byte) * " ")]


def condition_to_break(source, condition, body):
    """b becomes `if (!(b)) { break; }` at the start of the body."""
    if body is None:
        raise Reject("no body")
    first = body.children[1] if body.type == "compound_statement" else body
    indent = source.indent(first.start_byte)
    return [
        delete(condition),
        insert_before(
            first,
            f"if (!({text(condition)}))"
            + " {\n"
            + f"{(indent + 4) * ' '}break;\n"
            + f"{indent * ' '}"
            + "}"
            + f"\n{indent * ' '}",
        ),
    ]


def update_to_end(source, update, body):
    """c moves after the last statement of the body (skipped by `continue`: an original-method hazard)."""
    if body is None:
        raise Reject("no body")
    last = body.children[-2] if body.type == "compound_statement" else body
    return [delete(update), insert_after(last, f"\n{source.indent(last.start_byte) * ' '}{text(update)};")]


def loop_obc(node, source):
    """a; for(;b;c)"""
    init, condition, update, _ = for_parts(node)
    if not (condition and update) or init is None:
        raise Reject("needs a, b and c")
    return hoist_init(node, source, init)


def loop_aoc(node, source):
    """for(a;;c) { if (!(b)) break; ... }"""
    init, condition, update, body = for_parts(node)
    if not (init and update) or condition is None:
        raise Reject("needs a, b and c")
    return condition_to_break(source, condition, body)


def loop_abo(node, source):
    """for(a;b;) { ...; c; }"""
    init, condition, update, body = for_parts(node)
    if not (init and condition) or update is None:
        raise Reject("needs a, b and c")
    return update_to_end(source, update, body)


def loop_aoo(node, source):
    """for(a;;) { if (!(b)) break; ...; c; }"""
    init, condition, update, body = for_parts(node)
    if not init:
        raise Reject("needs a")
    edits = []
    if condition is not None:
        edits += condition_to_break(source, condition, body)
    if update is not None:
        edits += update_to_end(source, update, body)
    return edits


def loop_obo(node, source):
    """a; for(;b;) { ...; c; }"""
    init, condition, update, body = for_parts(node)
    if not condition:
        raise Reject("needs b")
    edits = []
    if init is not None:
        if text(init).strip() == MARKER:
            raise Reject("while-to-for marker")
        edits += hoist_init(node, source, init)
    if update is not None:
        edits += update_to_end(source, update, body)
    return edits


def loop_ooc(node, source):
    """a; for(;;c) { if (!(b)) break; ... }"""
    init, condition, update, body = for_parts(node)
    if not update:
        raise Reject("needs c")
    edits = []
    if init is not None:
        if text(init).strip() == MARKER:
            raise Reject("while-to-for marker")
        edits += hoist_init(node, source, init)
    if condition is not None:
        edits += condition_to_break(source, condition, body)
    return edits


def loop_ooo(node, source):
    """for(a;b;c) body -> a; for(;;) { if (!(b)) break; body; c; }

    Original-method hazards kept: `continue` skips c; a brace-less body only gets the
    break test, and loops testing ==/!= or carrying the while-to-for marker are left alone.
    """
    init, condition, update, body = for_parts(node)
    if body is None or body.type != "compound_statement" or loop_continues(body):
        raise Reject("break test or update would leave the loop body (brace-less body or continue)")
    edits = []
    if init is not None:
        if is_marker(init):
            raise Reject("while-to-for marker")
        edits += hoist_init(node, source, init)
    if condition is not None:
        if not not_equality_test(condition):
            raise Reject("equality loop condition")
        edits += condition_to_break(source, condition, body)
    if update is not None:
        edits += update_to_end(source, update, body)
    return edits


def loop_continues(body):
    """A `continue` of this loop (not of a nested loop) inside `body`."""
    stack = list(body.children)
    while stack:
        current = stack.pop()
        if current.type == "continue_statement":
            return True
        if current.type not in ["for_statement", "while_statement", "do_statement"]:
            stack.extend(current.children)
    return False


@guard("for(;;) loop")
def bare_for(node):
    """for(;;) or for(<declaration>;;) without the marker (raises like the original when only b/c exist)."""
    init, condition, update, _ = for_parts(node)
    if not init and not condition and not update:
        return True
    return init.type == "declaration" and not is_marker(init) and not condition and not update


marked_for = guard("for with the while-to-for marker")(lambda node: is_marker(for_parts(node)[0]))


@guard("outermost loop")
def outermost_loop(node):
    parent = node.parent
    while parent:
        if parent.type in ["while_statement", "do_statement", "for_statement"]:
            return False
        parent = parent.parent
    return True


LOOP = Matcher("[(while_statement) (do_statement) (for_statement)] @node").where(outermost_loop)


def loop_counter_update(body_statements, counter):
    """First top-level `i++;`/`i = ...;` whose identifiers (accumulated, as the original) are just the counter."""
    seen = set()
    for statement in body_statements:
        if (
            statement.type == "expression_statement"
            and statement.parent.type not in ["if_statement", "for_statement", "else_clause", "while_statement"]
            and statement.children[0].type in ["update_expression", "assignment_expression"]
        ):
            contain_id(statement.children[0], seen)
            if len(seen) == 1 and counter in seen:
                return statement
    return None


def while_to_for():
    """while(b) { ...; i++; } -> for(int identifier = 1; b; i++) { ... }

    The counter is an arbitrary identifier of b (list(set)[0], hash-seed dependent as in the
    original). The marker declaration lets the detector recognize rewritten loops. The update
    moves into the header only when it is the body's last statement and no continue skips it;
    otherwise it stays in the body and the header's third clause is empty. do-while loops are
    left alone (their body runs before the first test).
    """

    def rewrite(node, source):
        if node.type == "while_statement":
            condition = node.children[1].children[1]
            body_statements = node.children[2].children[1:-1]
            header = [delete_between(node.children[0].start_byte, node.children[1].end_byte)]
        elif node.type == "do_statement":
            raise Reject("do-while runs its body before the first test")
        else:
            raise Reject("already a for loop")
        names = set()
        contain_id(condition, names)
        if not names:
            raise Reject("condition without identifiers")
        if b"identifier" in node.text:
            raise Reject("the marker name is already used")
        update = loop_counter_update(body_statements, list(names)[0])
        if update is not None and (
            update != [item for item in body_statements if item.type != "comment"][-1]
            or loop_continues(node.children[2])
        ):
            update = None  # moving it into the header would reorder it (statements follow it, or continue skips it)
        edits = header + ([delete_between(update.prev_sibling.end_byte, update.end_byte)] if update else [])
        clause = text(update).replace(";", "") if update else ""
        return [*edits, insert_before(node, f"for({MARKER}; {text(condition)}; {clause})")]

    return rewrite


# ---------------------------------------------------------------- switch -> if


def switch_to_if(node, source):
    """switch(v){case x: s; ...} -> if(v == x){ s } else if ... else { last }  (first statement per case, as the original)."""
    variable = text(node.children[1].children[1])
    cases = [child for child in node.children[2].children if child.type == "case_statement"]
    indent = source.indent(node.start_byte)
    branches = []
    for position, case in enumerate(cases):
        label = text(case.children[1])
        if len(case.children) >= 4 and text(case.children[0]) == "case":
            statement = text(case.children[3])
        elif len(case.children) >= 3 and text(case.children[0]) == "default":
            statement = text(case.children[2])
        else:
            statement = ""
        body = f"{{\n{' ' * indent * 2}{statement}\n{' ' * indent}}}"
        if position == 0:
            branches.append(f"if({variable} == {label}){body}")
        elif position == len(cases) - 1:
            branches.append(f"{' ' * indent}else{body}")
        else:
            branches.append(f"{' ' * indent}else if({variable} == {label}){body}")
    return [replace(node, "\n".join(branches))]


# ---------------------------------------------------------------- extension rules (styles 14-20)
#
# Each pair rewrites syntax the rules above never match, keeps out of ==/!= operands and
# expanded comparisons (the hash-order and cmp rules read their text), and is an exact
# inverse of its partner for the canonical spacing it emits.

EXITS = ["return_statement", "throw_statement"]


def is_equality(node):
    return node.type == "binary_expression" and len(node.children) == 3 and text(node.children[1]) in EQUALITY


def expanded_junction(node):
    if node.type != "binary_expression" or len(node.children) != 3 or text(node.children[1]) not in ["&&", "||"]:
        return False
    first, second = node.children[0], node.children[2]
    return (
        first.type == "binary_expression"
        and second.type == "binary_expression"
        and len(first.children) == 3
        and len(second.children) == 3
        and text(first.children[1]) in RELATIONAL
        and text(second.children[1]) in EQUALITY
        and {text(first.children[0]).strip(), text(first.children[2]).strip()}
        == {text(second.children[0]).strip(), text(second.children[2]).strip()}
    )


@guard("not a template declaration misparsed as a comparison")
def real_comparison(node):
    """`std::set<std::string> names;` can parse as `std::set < std::string > names`: a comparison standing alone as
    a statement, or a chained relational test, is such a misparse (rewriting it breaks the declaration)."""
    if node.parent is not None and node.parent.type == "expression_statement":
        return False
    related = [node.children[0], node.children[-1], node.parent]
    return not any(
        other is not None
        and other.type == "binary_expression"
        and len(other.children) == 3
        and text(other.children[1]) in RELATIONAL
        for other in related
    )


IMPURE_EXPRESSIONS = ["call_expression", "assignment_expression", "update_expression", "comma_expression"]


def expansion_safe(dialect):
    """expcmp writes `a <= b` as `(a < b || a == b)`: both operands are evaluated twice, so they must be free of side
    effects, and in C++ (overloaded operators need not form a total order consistent with ==) one of them must be a
    number literal."""

    def test(node):
        if node.type == "parenthesized_expression":  # (a < b || a == b)
            node = node.children[1].children[0]
        operands = [node.children[0], node.children[2]]
        for operand in operands:
            stack = [operand]
            while stack:
                current = stack.pop()
                if current.type in IMPURE_EXPRESSIONS:
                    return False
                stack.extend(current.children)
        return dialect == "c" or any(operand.type == "number_literal" for operand in operands)

    return guard("operands free of side effects" + ("" if dialect == "c" else ", one a number literal"))(test)


def is_comparison(node):
    return (
        node.type == "binary_expression" and len(node.children) == 3 and text(node.children[1]) in EQUALITY + RELATIONAL
    )


@guard("outside comparison operands and expanded comparisons")
def outside_text_sensitive_operands(node):
    """The hash-order rules read ==/!= operand text and expcmp turns relational tests into
    expanded ==/!= tests, so rewriting inside any comparison could change those rules' view."""
    parent = node.parent
    while (
        parent is not None
        and not parent.type.endswith("statement")
        and parent.type not in ["declaration", "init_declarator"]
    ):
        if is_comparison(parent) or expanded_junction(parent):
            return False
        parent = parent.parent
    return True


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


def negated_group(node):
    """!(X): the form produced by the branch-swapping rules."""
    return (
        node.type == "unary_expression"
        and text(node.children[0]) == "!"
        and node.children[1].type == "parenthesized_expression"
        and len(node.children[1].children) == 3
    )


def negatable(expression):
    """Wrapping in !( ) changes no other rule's view: not ==/!=, not an expanded comparison, not already !(...)."""
    return (
        not is_equality(expression)
        and not expanded_junction(expression)
        and not negated_group(expression)
        and expression.type not in ["comma_expression", "assignment_expression"]
    )


def condition_value(statement):
    """The expression inside if (...) when the parentheses hold nothing else (no C++ init-statement)."""
    clause = statement.child_by_field_name("condition")
    if clause is None or len(clause.children) != 3 or clause.children[0].type != "(":
        return None
    return clause.children[1]


def nested_branching(node):
    """An if/else, or an exiting if that the else-after-return rule may give an else."""
    return has_else(node) or exiting_if(node)


def braced_if_else(negated_form):
    """if (c) { A } else { B } with two non-exiting blocks; c plain or !(c)."""

    def test(node):
        value = condition_value(node)
        clause = node.child_by_field_name("alternative")
        if (
            value is None
            or clause is None
            or len(clause.children) != 2
            or clause.children[1].type != "compound_statement"
        ):
            return False
        consequence = node.child_by_field_name("consequence")
        if consequence.type != "compound_statement" or exits(consequence) or exits(clause.children[1]):
            return False
        if contains(consequence, nested_branching) or contains(clause.children[1], nested_branching):
            return False
        if negated_form:
            return negated_group(value) and negatable(value.children[1].children[1])
        return negatable(value)

    return nodes("if_statement").where(
        guard("if (!(c)) {..} else {..}" if negated_form else "if (c) {..} else {..}")(test)
    )


def swap_branches(negate):
    """if (c) { A } else { B } -> if (!(c)) { B } else { A }   (and back)"""

    def rewrite(node, source):
        value = condition_value(node)
        consequence, alternative = (
            node.child_by_field_name("consequence"),
            node.child_by_field_name("alternative").children[1],
        )
        flipped = f"!({text(value)})" if negate else text(value.children[1].children[1])
        return [
            replace(value, flipped),
            replace(consequence, text(alternative)),
            replace(alternative, text(consequence)),
        ]

    return rewrite


def movable_conditional(negated_form):
    """c ? a : b whose branches may trade places (no comma or assignment operands)."""

    def test(node):
        if len(node.children) != 5:
            return False
        condition, a, b = node.children[0], node.children[2], node.children[4]
        if a.type in ["comma_expression", "assignment_expression"] or b.type in [
            "comma_expression",
            "assignment_expression",
        ]:
            return False
        if contains(node, lambda child: child.type == "conditional_expression"):
            return False
        if negated_form:
            return negated_group(condition) and negatable(condition.children[1].children[1])
        return negatable(condition)

    return nodes("conditional_expression").where(
        guard("!(c) ? a : b" if negated_form else "c ? a : b")(test), outside_text_sensitive_operands
    )


def swap_conditional(negate):
    """c ? a : b -> !(c) ? b : a   (and back; the operands trade places, layout kept)"""

    def rewrite(node, source):
        condition, a, b = node.children[0], node.children[2], node.children[4]
        flipped = f"!({text(condition)})" if negate else text(condition.children[1].children[1])
        return [replace(condition, flipped), replace(a, text(b)), replace(b, text(a))]

    return rewrite


CONJUNCT_TYPES = [
    "binary_expression",
    "unary_expression",
    "identifier",
    "call_expression",
    "field_expression",
    "subscript_expression",
    "number_literal",
    "true",
    "false",
    "parenthesized_expression",
    "pointer_expression",
]


def conjunct(node):
    """An operand that needs no parentheses next to && (binds tighter than &&)."""
    if node.type not in CONJUNCT_TYPES:
        return False
    return node.type != "binary_expression" or text(node.children[1]) not in ["&&", "||"]


def no_else(node):
    return node.child_by_field_name("alternative") is None


@guard("if (a && b) { S } without else")
def conjunctive_if(node):
    value = condition_value(node)
    consequence = node.child_by_field_name("consequence")
    if value is None or not no_else(node) or consequence.type != "compound_statement" or exits(consequence):
        return False
    return (
        value.type == "binary_expression"
        and text(value.children[1]) == "&&"
        and not expanded_junction(value)
        and conjunct(value.children[0])
        and conjunct(value.children[2])
        and value.text[value.children[0].end_byte - value.start_byte : value.children[2].start_byte - value.start_byte]
        == b" && "
    )


@guard("if (a) if (b) { S } without else")
def nested_if(node):
    outer, inner = condition_value(node), None
    consequence = node.child_by_field_name("consequence")
    if outer is None or not no_else(node) or consequence.type != "if_statement" or not no_else(consequence):
        return False
    inner = condition_value(consequence)
    body = consequence.child_by_field_name("consequence")
    if inner is None or body.type != "compound_statement" or exits(body):
        return False
    if node.text[outer.end_byte - node.start_byte : inner.start_byte - node.start_byte] != b") if (":
        return False
    return (
        conjunct(outer)
        and conjunct(inner)
        and not (
            outer.type == "binary_expression"
            and inner.type == "binary_expression"
            and text(outer.children[1]) in RELATIONAL
            and text(inner.children[1]) in EQUALITY
            and {text(outer.children[0]), text(outer.children[2])} == {text(inner.children[0]), text(inner.children[2])}
        )
    )


def split_conjunction(node, source):
    """if (a && b) { S } -> if (a) if (b) { S }"""
    value = condition_value(node)
    return [Edit(value.children[0].end_byte, value.children[2].start_byte, ") if (")]


def join_conjunction(node, source):
    """if (a) if (b) { S } -> if (a && b) { S }"""
    outer, inner = condition_value(node), condition_value(node.child_by_field_name("consequence"))
    return [Edit(outer.end_byte, inner.start_byte, " && ")]


def parameter_with(declarator_test, label):
    """A function parameter `T <declarator>` with a builtin non-void T (an array of an incomplete
    struct or of void is invalid), main's parameters excluded."""

    def test(node):
        declarator, element = node.child_by_field_name("declarator"), node.child_by_field_name("type")
        if (
            declarator is None
            or element is None
            or element.type not in ["primitive_type", "sized_type_specifier"]
            or text(element) == "void"
            or not declarator_test(declarator)
        ):
            return False
        function = node.parent.parent
        return not (
            function is not None and function.type == "function_declarator" and text(function.children[0]) == "main"
        )

    return nodes("parameter_declaration").where(guard(label)(test))


def canonical(declarator, spelling):
    """`T name[]` / `T *name`: one space after the type and no spaces inside the declarator."""
    before = declarator.prev_sibling
    gap = declarator.parent.text[
        before.end_byte - declarator.parent.start_byte : declarator.start_byte - declarator.parent.start_byte
    ]
    return gap == b" " and text(declarator) == spelling


ARRAY_PARAMETER = parameter_with(
    lambda declarator: (
        declarator.type == "array_declarator"
        and [child.type for child in declarator.children] == ["identifier", "[", "]"]
        and canonical(declarator, text(declarator.children[0]) + "[]")
    ),
    "T name[]",
)
POINTER_PARAMETER = parameter_with(
    lambda declarator: (
        declarator.type == "pointer_declarator"
        and [child.type for child in declarator.children] == ["*", "identifier"]
        and canonical(declarator, "*" + text(declarator.children[1]))
    ),
    "T *name",
)


def array_to_pointer_parameter(node, source):
    """int a[] -> int *a  (array parameters are adjusted to pointers)"""
    declarator = node.child_by_field_name("declarator")
    return [replace(declarator, "*" + text(declarator.children[0]))]


def pointer_to_array_parameter(node, source):
    """int *a -> int a[]"""
    declarator = node.child_by_field_name("declarator")
    return [replace(declarator, text(declarator.children[1]) + "[]")]


def void_function(node):
    """void f(...) { ... } other than main, with a non-empty body."""
    declarator = node.child_by_field_name("declarator")
    body = node.child_by_field_name("body")
    if (
        node.children[0].type != "primitive_type"
        or text(node.children[0]) != "void"
        or declarator is None
        or declarator.type != "function_declarator"
        or text(declarator.children[0]) == "main"
        or body is None
    ):
        return False
    return any(child.type != "comment" for child in body.children[1:-1])


def statements(body):
    return [child for child in body.children[1:-1] if child.type != "comment"]


@guard("void function ending with return;")
def ends_with_bare_return(node):
    if not void_function(node):
        return False
    body = statements(node.child_by_field_name("body"))
    return len(body) >= 2 and body[-1].type == "return_statement" and len(body[-1].children) == 2


@guard("void function without a final return")
def ends_without_return(node):
    return void_function(node) and statements(node.child_by_field_name("body"))[-1].type != "return_statement"


def add_final_return(node, source):
    """void f() { ...; } -> void f() { ...; return; }"""
    last = statements(node.child_by_field_name("body"))[-1]
    indent = source.leading(last)
    if indent is None:
        raise Reject("last statement shares its line")
    return [insert_after(last, f"\n{indent}return;")]


def drop_final_return(node, source):
    """void f() { ...; return; } -> void f() { ...; }"""
    final = statements(node.child_by_field_name("body"))[-1]
    return [delete_between(final.prev_sibling.end_byte, final.end_byte)]


def void_function_body(block):
    """The top-level block of a void function, whose last statement the void-return rule edits."""
    return block.parent is not None and block.parent.type == "function_definition" and void_function(block.parent)


def in_main(node):
    parent = node.parent
    while parent is not None:
        if parent.type == "function_definition":
            declarator = parent.child_by_field_name("declarator")
            return (
                declarator is not None
                and declarator.type == "function_declarator"
                and text(declarator.children[0]) == "main"
            )
        parent = parent.parent
    return False


def raw_text_free(node):
    return not any(marker in node.text for marker in [b'R"', b"\\\n"])


def exits(block):
    """The compound statement always leaves the function: it ends with return/throw, or with an
    if/else whose branches all exit (so both forms of the else-after-return rule count)."""
    items = statements(block) if block.type == "compound_statement" else [block]
    if not items:
        return False
    last = items[-1]
    if last.type in EXITS:
        return True
    if last.type == "compound_statement":
        return exits(last)
    if last.type != "if_statement" or last.child_by_field_name("alternative") is None:
        return False
    alternative = [child for child in last.child_by_field_name("alternative").children if child.is_named]
    return exits(last.child_by_field_name("consequence")) and len(alternative) == 1 and exits(alternative[0])


def exiting_if(node):
    consequence = node.child_by_field_name("consequence") if node.type == "if_statement" else None
    return consequence is not None and consequence.type == "compound_statement" and exits(consequence)


def bare_exiting_if(node):
    return exiting_if(node) and no_else(node)


def exiting_if_else(node):
    clause = node.child_by_field_name("alternative") if exiting_if(node) else None
    return clause is not None and len(clause.children) == 2 and clause.children[1].type == "compound_statement"


def holds_exiting_if(items):
    return any(exiting_if(item) or contains(item, exiting_if) for item in items)


@guard("the only exiting if/else, last in a block outside main, its else-block free of exiting ifs")
def exiting_braced_if_else(node):
    if (
        not exiting_if_else(node)
        or node.parent.type != "compound_statement"
        or node.parent.children[-2] != node
        or in_main(node)
        or void_function_body(node.parent)
    ):
        return False
    block = node.child_by_field_name("alternative").children[1]
    body = statements(block)
    return (
        bool(body)
        and not any(child.type == "declaration" for child in block.children)
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


@guard("the only exiting if of a block outside main, followed by the rest of the block")
def exiting_braced_if_then_rest(node):
    if (
        not bare_exiting_if(node)
        or node.parent.type != "compound_statement"
        or in_main(node)
        or void_function_body(node.parent)
    ):
        return False
    rest = [item for item in trailing_statements(node) if item.type != "comment"]
    return (
        bool(rest)
        and sum(bare_exiting_if(item) for item in statements(node.parent)) == 1
        and not holds_exiting_if(rest)
        and not any(item.type == "declaration" for item in rest)
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
    return [Edit(node.child_by_field_name("consequence").end_byte, clause.end_byte, f"\n{outer}{moved}")]


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


POINTER_OBJECT = ["identifier", "field_expression", "call_expression"]


def member_dereference(pointer):
    """The `*p` of `(*p).x`, as written by the member-access rule itself."""
    group = pointer.parent
    return (
        group.type == "parenthesized_expression"
        and len(group.children) == 3
        and group.parent.type == "field_expression"
        and group.parent.children[0] == group
        and group.parent.children[1].type == "."
    )


@guard("outside *(...) and subscripts")
def outside_pointer_arithmetic(node):
    """The array rules count and rewrite pointer expressions and subscripts around this node."""
    parent = node.parent
    while parent is not None:
        if parent.type == "subscript_expression" or (
            parent.type == "pointer_expression" and not member_dereference(parent)
        ):
            return False
        parent = parent.parent
    return True


@guard("p->x on a plain postfix object")
def arrow_access(node):
    return node.children[1].type == "->" and node.children[0].type in POINTER_OBJECT


@guard("(*p).x on a plain postfix object")
def dereferenced_access(node):
    group = node.children[0]
    if node.children[1].type != "." or group.type != "parenthesized_expression" or len(group.children) != 3:
        return False
    pointer = group.children[1]
    return (
        pointer.type == "pointer_expression"
        and text(pointer.children[0]) == "*"
        and pointer.children[1].type in POINTER_OBJECT
    )


def arrow_to_dereference(node, source):
    """p->x -> (*p).x   (only `(*` and the operator change, so chains like a->b->c are independent edits)"""
    return [insert_before(node.children[0], "(*"), replace(node.children[1], ").")]


def dereference_to_arrow(node, source):
    """(*p).x -> p->x"""
    group = node.children[0]
    target = group.children[1].children[1]
    return [
        delete_between(group.start_byte, target.start_byte),
        delete_between(target.end_byte, node.children[1].end_byte),
        insert_after(target, "->"),
    ]


# ---------------------------------------------------------------- registry


def c_family_rules(dialect):
    equality = BINARY.where(
        guard("not an `in` test")(lambda node: node.children[1].text != b"in"),
        operator_in(*EQUALITY),
        ~in_expanded_comparison,
    )
    equality_any = BINARY.where(operator_in(*EQUALITY), ~in_expanded_comparison)
    if dialect == "c":
        compound = nodes("assignment_expression").where(
            guard("compound assignment")(lambda node: node.child_count >= 2 and text(node.children[1]) in COMPOUND)
        )
    else:
        compound = nodes("assignment_expression").where(
            guard("compound assignment of a non-binary value")(
                lambda node: (
                    node.child_count == 3
                    and text(node.children[1]) in COMPOUND
                    and node.children[2].type != "binary_expression"
                )
            )
        )
    rules = {
        "2.1": nodes("assignment_expression").where(self_assignment).rule(to_compound),
        "2.2": compound.rule(from_compound),
        "2.3": equality.where(~negated, binary, real_comparison).rule(negate_equality("==", "!=")),
        "2.4": negated_test("!=").rule(remove_negation("==")),
        "2.5": equality.where(~negated, binary, real_comparison).rule(negate_equality("!=", "==")),
        "2.6": negated_test("==").rule(remove_negation("!=")),
        "2.7": BINARY.where(operator_in(">", ">="), binary, real_comparison).rule(mirror({">": "<", ">=": "<="})),
        "2.8": BINARY.where(operator_in("<", "<="), binary, real_comparison).rule(mirror({"<": ">", "<=": ">="})),
        "2.9": BINARY.where(operator_in(*RELATIONAL), ~in_expanded_comparison, binary, real_comparison)
        .where(expansion_safe(dialect))
        .rule(expand_comparison),
        "2.10": nodes("parenthesized_expression")
        .where(expanded_comparison, expansion_safe(dialect))
        .rule(contract_comparison),
        "2.11": equality_any.where(binary, real_comparison).rule(hash_order("==", "!=", True)),
        "2.12": equality_any.where(binary, real_comparison).rule(hash_order("==", "!=", False)),
        "2.13": equality_any.where(binary, real_comparison).rule(hash_order("!=", "==", True)),
        "2.14": equality_any.where(binary, real_comparison).rule(hash_order("!=", "==", False)),
        "3.1": nodes("update_expression")
        .where(update_outside_index_call_assignment, update_operand_at(0))
        .rule(to_prefix),
        "3.2": nodes("update_expression")
        .where(update_outside_index_call_assignment, update_operand_at(1))
        .rule(to_postfix),
        "4.1": MAIN.rule(main_signature("int", "void", True)),
        "4.2": MAIN.rule(main_signature("int", "void", False)),
        "4.3": MAIN.rule(main_signature("int", "none", True)),
        "4.4": MAIN.rule(main_signature("int", "none", False)),
        "4.5": MAIN.rule(main_signature("int", "args", True)),
        "4.6": MAIN.rule(main_signature("int", "args", False)),
        "4.7": MAIN.rule(main_signature("void", "args", False)),
        "4.8": MAIN.rule(main_signature("void", "none", False)),
        "6.1": nodes("declaration").where(multi_name_declaration).rule(split_declaration),
        "6.2": Matcher("((_ (declaration)) @node) ((ERROR (declaration)) @node)")
        .where(repeated_declaration_type)
        .rule(merge_declarations),
        "7.1": FOR.rule(loop_obc),
        "7.2": FOR.rule(loop_aoc),
        "7.3": FOR.rule(loop_abo),
        "7.4": FOR.rule(loop_aoo),
        "7.5": FOR.rule(loop_obo),
        "7.6": FOR.rule(loop_ooc),
        "7.7": FOR.rule(loop_ooo, target=FOR.where(bare_for)),
        "7.8": LOOP.rule(while_to_for(), target=FOR.where(marked_for)),
        "8.1": nodes("switch_statement").rule(switch_to_if),
        "14.1": braced_if_else(negated_form=True).where(well_formed).rule(swap_branches(negate=False)),
        "14.2": braced_if_else(negated_form=False).where(well_formed).rule(swap_branches(negate=True)),
        "15.1": movable_conditional(negated_form=True).where(well_formed).rule(swap_conditional(negate=False)),
        "15.2": movable_conditional(negated_form=False).where(well_formed).rule(swap_conditional(negate=True)),
        "16.1": nodes("if_statement").where(nested_if).where(well_formed).rule(join_conjunction),
        "16.2": nodes("if_statement").where(conjunctive_if).where(well_formed).rule(split_conjunction),
        "17.1": POINTER_PARAMETER.where(well_formed).rule(pointer_to_array_parameter),
        "17.2": ARRAY_PARAMETER.where(well_formed).rule(array_to_pointer_parameter),
        "18.1": nodes("function_definition").where(ends_with_bare_return).where(well_formed).rule(drop_final_return),
        "18.2": nodes("function_definition").where(ends_without_return).where(well_formed).rule(add_final_return),
        "20.1": nodes("if_statement").where(exiting_braced_if_then_rest).where(well_formed).rule(add_braced_else),
        "20.2": nodes("if_statement").where(exiting_braced_if_else).where(well_formed).rule(drop_braced_else),
    }
    if dialect == "c":
        rules.update(
            {
                "19.1": nodes("field_expression")
                .where(dereferenced_access, outside_pointer_arithmetic, outside_text_sensitive_operands)
                .where(well_formed)
                .rule(dereference_to_arrow),
                "19.2": nodes("field_expression")
                .where(arrow_access, outside_pointer_arithmetic, outside_text_sensitive_operands)
                .where(well_formed)
                .rule(arrow_to_dereference),
                "5.1": nodes("declaration").where(static_array_declaration, movable_array).rule(static_to_dynamic),
                "5.2": nodes("declaration")
                .where(
                    guard("malloc-initialised pointer")(
                        lambda node: any(malloc_declarator(child) for child in node.children)
                    ),
                    movable_allocation,
                )
                .rule(dynamic_to_static),
                "5.3": nodes("subscript_expression")
                .where(
                    plain_subscript,
                    ~guard("nested subscript")(nested_brackets),
                    ~guard("pointer arithmetic inside")(lambda node: bool(POINTER_ARITHMETIC.search(text(node)))),
                    guard("at most three dimensions")(lambda node: array_dimension(node) < 4),
                )
                .rule(array_to_pointer),
                "5.4": nodes("pointer_expression").where(outermost_pointer_arithmetic).rule(pointer_to_array),
            }
        )
    return rules


RULES = c_family_rules("c")


# ---------------------------------------------------------------- extension rules (rule set "extended")
#
# Each pair is an exact inverse on the forms it accepts, and neither direction creates or removes a candidate of a
# legacy pair: comparisons (equality, hash order, expcmp) and `a = a <op> b` are left alone, and in C the operands
# of array subscripts and dereferences belong to the array/pointer rules (5.3/5.4).


def return_value(node):
    """The value of `return <value>;` when `return` and the value are separated by exactly one space, else None."""
    values = [child for child in node.named_children if child.type != "comment"]
    if len(values) != 1 or len(values) != len(node.named_children):
        return None
    value, keyword = values[0], node.children[0]
    return value if node.text[keyword.end_byte - node.start_byte : value.start_byte - node.start_byte] == b" " else None


def returns_decltype(node):
    """Inside a function or lambda whose declared return type uses decltype (`return (x);` would return a reference)."""
    parent = node.parent
    while parent is not None and parent.type not in ["function_definition", "lambda_expression"]:
        parent = parent.parent
    if parent is None:
        return False
    body = parent.child_by_field_name("body")
    return b"decltype" in parent.text[: (body.start_byte if body is not None else parent.end_byte) - parent.start_byte]


UNPARENTHESIZABLE = ["parenthesized_expression", "initializer_list"]


@guard("inside no comparison, also through enclosing lambdas")
def outside_all_comparisons(node):
    """The hash-order and expcmp rules read the whole text of comparison operands, which can hold lambdas with
    statements of their own, so every ancestor counts (not only those up to the enclosing statement)."""
    parent = node.parent
    while parent is not None:
        if is_comparison(parent) or expanded_junction(parent):
            return False
        parent = parent.parent
    return True


def logical(node):
    """`a && b` / `a || b`: expcmp (2.10) reads `(a < b || a == b)` with its parentheses."""
    return node.type == "binary_expression" and len(node.children) == 3 and text(node.children[1]) in ["&&", "||"]


def holds_operation(node):
    """A binary operation inside the operand, which could be a candidate of its own: one rewrite pass would then edit
    nested text twice (`a[i + 1] + 2`), so neither is taken."""
    stack = list(node.children)
    while stack:
        current = stack.pop()
        if current.type == "binary_expression":
            return True
        stack.extend(current.children)
    return False


@guard("return E; with E not parenthesized, a braced list or && / ||")
def plain_return(node):
    value = return_value(node)
    return (
        value is not None and value.type not in UNPARENTHESIZABLE and not logical(value) and not returns_decltype(node)
    )


@guard("return (E); with the parentheses directly around E, not && / ||")
def parenthesized_return(node):
    value = return_value(node)
    if value is None or value.type != "parenthesized_expression" or len(value.children) != 3:
        return False
    inner = value.children[1]
    return (
        inner.type not in UNPARENTHESIZABLE
        and not logical(inner)
        and value.text == b"(" + inner.text + b")"
        and not returns_decltype(node)
    )


def add_return_parentheses(node, source):
    """return E; -> return (E);"""
    value = return_value(node)
    return [insert_before(value, "("), insert_after(value, ")")]


def drop_return_parentheses(node, source):
    """return (E); -> return E;"""
    value = return_value(node)
    return [delete(value.children[0]), delete(value.children[2])]


LITERAL_OPERATORS = ["+", "*"]


def literal_operation(dialect, literal_left):
    """`x <op> LITERAL` (literal_left=False) or `LITERAL <op> x` for + and *, with x a plain operand."""
    atomic = ["identifier", "call_expression", "field_expression", "parenthesized_expression"]
    if dialect != "c":
        atomic.append("subscript_expression")

    def test(node):
        if len(node.children) != 3 or text(node.children[1]) not in LITERAL_OPERATORS:
            return False
        left, right = node.children[0], node.children[2]
        literal, other = (left, right) if literal_left else (right, left)
        if literal.type != "number_literal" or other.type not in atomic or holds_operation(other):
            return False
        parent = node.parent
        if (
            parent is not None
            and parent.type == "assignment_expression"
            and len(parent.children) == 3
            and text(parent.children[1]) == "="
            and text(parent.children[0]).strip() == text(other).strip()
        ):
            return False  # a = a + 1 / a = 1 + a: the compound-assignment rules read the operand order
        if dialect == "c":
            ancestor = parent
            while ancestor is not None and not ancestor.type.endswith("statement"):
                if ancestor.type in ["subscript_expression", "pointer_expression"]:
                    return False
                ancestor = ancestor.parent
        return True

    side = "literal first" if literal_left else "literal last"
    return guard(f"{side} in + or * with a plain other operand (not a self-assignment)")(test)


def swap_operands(node, source):
    """x + 1 -> 1 + x (and back): the operands trade places, the operator and spacing stay."""
    left, right = node.children[0], node.children[2]
    return [replace(left, text(right)), replace(right, text(left))]


COMPARING_OPERATORS = EQUALITY + RELATIONAL + ["&&", "||"]


def assigned_value(node):
    """The value of `x = value` / `T x = value` with one space after `=` and the value on one line, else None."""
    if len(node.children) != 3 or node.children[1].type != "=":
        return None
    value = node.children[2]
    gap = node.text[node.children[1].end_byte - node.start_byte : value.start_byte - node.start_byte]
    return value if gap == b" " and b"\n" not in value.text else None


def assigned_operation(dialect):
    """`value` when it is an arithmetic or bitwise operation (no comparison or logic, and in C++ no << / >> that
    stream rules read) neither of whose operands repeats the target (2.x reads `a = a <op> b`), else None."""
    excluded = COMPARING_OPERATORS + (["<<", ">>"] if dialect != "c" else [])

    def test(node, value):
        if value is None or value.type != "binary_expression" or len(value.children) != 3:
            return None
        if text(value.children[1]) in excluded:
            return None
        target = text(node.children[0]).strip()
        return None if target in [text(value.children[0]).strip(), text(value.children[2]).strip()] else value

    return test


def assignment_parentheses(dialect, parenthesized):
    operation = assigned_operation(dialect)

    def test(node):
        value = assigned_value(node)
        if not parenthesized:
            return operation(node, value) is not None
        if value is None or value.type != "parenthesized_expression" or len(value.children) != 3:
            return False
        return value.text == b"(" + value.children[1].text + b")" and operation(node, value.children[1]) is not None

    form = "x = (a <op> b)" if parenthesized else "x = a <op> b"
    return guard(f"{form}: an arithmetic or bitwise operation not repeating x")(test)


def drop_assigned_parentheses(node, source):
    value = assigned_value(node)
    return [delete(value.children[0]), delete(value.children[2])]


def add_assigned_parentheses(node, source):
    value = assigned_value(node)
    return [insert_before(value, "("), insert_after(value, ")")]


ASSIGNMENTS = Matcher("[(assignment_expression) (init_declarator)] @node")


def c_extension_rules(dialect, operand_guards=()):
    rules = {
        "40.1": nodes("return_statement")
        .where(parenthesized_return, outside_all_comparisons)
        .where(well_formed)
        .rule(drop_return_parentheses),
        "40.2": nodes("return_statement")
        .where(plain_return, outside_all_comparisons)
        .where(well_formed)
        .rule(add_return_parentheses),
        "41.1": BINARY.where(literal_operation(dialect, True), outside_all_comparisons, *operand_guards)
        .where(well_formed)
        .rule(swap_operands),
        "41.2": BINARY.where(literal_operation(dialect, False), outside_all_comparisons, *operand_guards)
        .where(well_formed)
        .rule(swap_operands),
        "45.1": ASSIGNMENTS.where(assignment_parentheses(dialect, True), outside_all_comparisons)
        .where(well_formed)
        .rule(drop_assigned_parentheses),
        "45.2": ASSIGNMENTS.where(assignment_parentheses(dialect, False), outside_all_comparisons)
        .where(well_formed)
        .rule(add_assigned_parentheses),
    }
    if dialect != "c":
        # Range-for bodies only: the C loop rules (7.x) read the bodies of for, while and do loops.
        rules["46.1"] = (
            nodes("for_range_loop")
            .where(
                guard("braced simple body")(lambda node: braced_layout(node, "compound_statement") is not None),
                outside_all_comparisons,
            )
            .where(well_formed)
            .rule(drop_braces("compound_statement"))
        )
        rules["46.2"] = (
            nodes("for_range_loop")
            .where(guard("brace-less simple body")(lambda node: bare_layout(node) is not None), outside_all_comparisons)
            .where(well_formed)
            .rule(add_braces)
        )
    return rules


EXTENSION_RULES = c_extension_rules("c")

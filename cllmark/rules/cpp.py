"""C++ rewrite rules: the C-family rules (C++ dialect) plus stdio <-> iostream rules."""

import re

from .c import array_dimension, c_extension_rules, c_family_rules, contain_id, nodes, outside_text_sensitive_operands
from .engine import Reject, guard, replace, text, well_formed

FORMAT_SPECIFIER = re.compile(r"%[-+]?\d*\.*\d*[cCdiouxXeEfgGsSpn]")


def declared_types(block):
    """{name: type} for the declarations directly in `block` (arrays/pointers get one '*' per level)."""
    types = {}
    for child in block.children:
        if child.type != "declaration":
            continue
        kind = text(child.children[0])
        for declarator in child.children[1:-1]:
            if declarator.type == ",":
                continue
            if declarator.type == "init_declarator":
                declarator = declarator.children[0]
            if declarator.type == "array_declarator":
                types[text(declarator)] = kind + array_dimension(declarator) * "*"
            elif declarator.type == "pointer_declarator":
                stars = text(declarator).count("*")
                types[text(declarator)[stars:]] = kind + stars * "*"
            else:
                types[text(declarator)] = kind
    return types


def format_of(kind):
    if kind in ["int", "short", "short int", "int short", "unsigned", "unsigned int", "unsigned short int"]:
        return "%" + ("u" if "unsigned" in kind else "") + "d"
    if kind in ["char", "unsigned char"]:
        return "%" + ("u" if "unsigned" in kind else "") + "c"
    if kind in ["char*", "string"]:
        return "%s"
    if kind in ["double", "float"]:
        return "%f"
    if kind in ["long", "unsigned long long"]:
        return "%" + ("u" if "unsigned" in kind else "") + "ld"
    if kind in ["long long", "unsinged long long"]:
        return "%" + ("u" if "unsigned" in kind else "") + "lld"
    return None


def stream_to_format(node, stream):
    """cout/cin chain -> (format string, ", args"), typing operands from enclosing declarations; None if unknown."""
    items, item_nodes = [], []
    current = node.children[0]
    while current:
        items.insert(0, text(current.children[2]))
        item_nodes.insert(0, current.children[2])
        current = current.children[0]
        if text(current) == stream:
            break
    visible = {}
    while current:
        if current.type == "compound_statement":
            visible.update(declared_types(current))
        current = current.parent
    types = {}
    for name, kind in visible.items():
        types[name[: name.find("[")] if "[" in name else name] = kind
    format_text, arguments, kind = "", [], ""
    for position, item in enumerate(items):
        if item[0] == '"' and item[-1] == '"':
            format_text += item[1:-1]
            continue
        if item == "endl":
            format_text += "\\n"
            continue
        name = item
        if item not in types:
            unknown = True
            if item_nodes[position].type in ["binary_expression", "cast_expression"]:
                names = set()
                contain_id(item_nodes[position], names)
                if names:
                    name = list(names)[0]
                    if name not in types:
                        if "[" in name and name[: name.find("[")] in types:
                            kind = types[name[: name.find("[")]][: -name.count("[")]
                            unknown = False
                    else:
                        kind = types[name]
                        unknown = False
            if "[" in name and name[: name.find("[")] in types:
                kind = types[name[: name.find("[")]][: -name.count("[")]
                unknown = False
            if unknown:
                return None
        else:
            kind = types[item]
        specifier = format_of(kind)
        if specifier is None:
            return None
        format_text += specifier
        if stream == "cin" and not (item in types and types[item] == "char*"):
            item = "&" + item
        arguments.append(item)
    for position, argument in enumerate(arguments):
        if argument in types and types[argument] == "string":
            if stream == "cin":
                return None
            arguments[position] += ".c_str()"
    joined = ", ".join(arguments)
    return format_text, (", " + joined if joined else "")


@guard("cout << ... statement")
def cout_statement(node):
    return stream_head(node, "cout", "<<")


@guard("cin >> ... statement")
def cin_statement(node):
    return stream_head(node, "cin", ">>")


def stream_head(node, stream, operator):
    current = node.children[0]
    while current:
        if current.type != "binary_expression":
            return text(current) == stream and current.next_sibling.type == operator
        current = current.children[0]
    return False


def call_to(name):
    return nodes("call_expression").where(
        guard(f"{name}(...) call")(
            lambda node: (
                node.child_by_field_name("function") is not None and text(node.child_by_field_name("function")) == name
            )
        )
    )


def printf_to_cout(node, source):
    """printf("a %d b", x) -> cout << "a " << x << " b" """
    content = text(node.children[1])[1:-1]
    format_text = content.split('",')[0][1:-1]
    arguments = [part.replace(" ", "") for part in content.split('",')[1:]]
    positions = [(match.start(), match.end()) for match in FORMAT_SPECIFIER.finditer(format_text)]
    if len(positions) != len(arguments):
        raise Reject("argument count differs from format specifiers")
    if positions:
        pieces = [(0, positions[0][0])] + [(positions[i - 1][1], positions[i][0]) for i in range(1, len(positions))]
        pieces.append((positions[-1][1], len(format_text)))
    else:
        pieces = [(0, len(format_text))]
    stream = ["cout"]
    for index, (start, end) in enumerate(pieces):
        if (start, end) != (0, 0) and start != len(format_text):
            stream.append(f'"{format_text[start:end]}"')
        if index < len(arguments):
            if "?" in arguments[index]:
                raise Reject("conditional argument")
            stream.append(arguments[index])
    return [replace(node, " << ".join(part for part in stream if part not in ["''", '""']))]


def cout_to_printf(node, source):
    converted = stream_to_format(node, "cout")
    if converted is None:
        raise Reject("operand type unknown")
    return [replace(node, f'printf("{converted[0]}"{converted[1]});')]


def scanf_to_cin(node, source):
    """scanf("%d", &x) -> cin >> x"""
    content = text(node.children[1])[1:-1]
    if '"' in content:
        content = content[content.find('"', content.count('"')) + 1 :]
        content = content[content.find(",") + 1 :]
    stream = ["cin"] + [part.replace(" ", "").replace("&", "") for part in content.split(",")]
    return [replace(node, " >> ".join(part for part in stream if part != '"'))]


def cin_to_scanf(node, source):
    converted = stream_to_format(node, "cin")
    if converted is None:
        raise Reject("operand type unknown")
    return [replace(node, f'scanf("{converted[0]}"{converted[1]});')]


# ---------------------------------------------------------------- extension rules (styles 21-22)

SIMPLE_TYPES = ["primitive_type", "type_identifier", "sized_type_specifier", "qualified_identifier", "template_type"]


@guard("typedef T Name;")
def simple_typedef(node):
    return [child.type for child in node.children] == [
        "typedef",
        node.children[1].type,
        "type_identifier",
        ";",
    ] and node.children[1].type in SIMPLE_TYPES


@guard("using Name = T;")
def simple_alias(node):
    kinds = [child.type for child in node.children]
    if kinds != ["using", "type_identifier", "=", "type_descriptor", ";"]:
        return False
    descriptor = node.children[3]
    return len(descriptor.children) == 1 and descriptor.children[0].type in SIMPLE_TYPES


def typedef_to_using(node, source):
    """typedef long long ll; -> using ll = long long;"""
    return [replace(node, f"using {text(node.children[2])} = {text(node.children[1])};")]


def using_to_typedef(node, source):
    """using ll = long long; -> typedef long long ll;"""
    return [replace(node, f"typedef {text(node.children[3])} {text(node.children[1])};")]


PRIMARY_OPERAND = ["identifier", "call_expression", "field_expression", "subscript_expression", "number_literal"]


@guard("not a direct << / >> stream operand")
def not_stream_operand(node):
    return not (node.parent.type == "binary_expression" and text(node.parent.children[1]) in ["<<", ">>"])


@guard("(T)x with a one-word builtin T")
def c_style_cast(node):
    descriptor, value = node.child_by_field_name("type"), node.child_by_field_name("value")
    if (
        descriptor is None
        or len(descriptor.children) != 1
        or descriptor.children[0].type != "primitive_type"
        or value is None
    ):
        return False
    closing = node.children[2]
    if closing.type != ")" or value.start_byte != closing.end_byte:
        return False  # canonical (T)x: the operand directly follows the closing parenthesis
    if value.type == "parenthesized_expression":
        return len(value.children) == 3 and value.children[1].type not in [*PRIMARY_OPERAND, "comma_expression"]
    return value.type in PRIMARY_OPERAND


@guard("T(x) with a one-word builtin T")
def functional_cast(node):
    function, arguments = node.child_by_field_name("function"), node.child_by_field_name("arguments")
    if function is None or function.type != "primitive_type" or arguments is None:
        return False
    values = [child for child in arguments.children if child.is_named]
    return len(values) == 1 and len(arguments.children) == 3 and values[0].type != "comma_expression"


def to_functional_cast(node, source):
    """(double)x -> double(x);  (double)(a + b) -> double(a + b)"""
    value = node.child_by_field_name("value")
    inner = value.children[1] if value.type == "parenthesized_expression" else value
    return [replace(node, f"{text(node.child_by_field_name('type'))}({text(inner)})")]


def to_c_style_cast(node, source):
    """double(x) -> (double)x;  double(a + b) -> (double)(a + b)"""
    value = node.child_by_field_name("arguments").children[1]
    operand = text(value) if value.type in PRIMARY_OPERAND else f"({text(value)})"
    return [replace(node, f"({text(node.child_by_field_name('function'))}){operand}")]


RULES = {
    **c_family_rules("cpp"),
    "21.1": nodes("type_definition").where(simple_typedef).where(well_formed).rule(typedef_to_using),
    "21.2": nodes("alias_declaration").where(simple_alias).where(well_formed).rule(using_to_typedef),
    "22.1": nodes("cast_expression")
    .where(c_style_cast, not_stream_operand, outside_text_sensitive_operands)
    .where(well_formed)
    .rule(to_functional_cast),
    "22.2": nodes("call_expression")
    .where(functional_cast, not_stream_operand, outside_text_sensitive_operands)
    .where(well_formed)
    .rule(to_c_style_cast),
    "9.1": call_to("printf").where(well_formed).rule(printf_to_cout),
    "9.2": nodes("expression_statement").where(cout_statement).where(well_formed).rule(cout_to_printf),
    "9.3": call_to("scanf").where(well_formed).rule(scanf_to_cin),
    "9.4": nodes("expression_statement").where(cin_statement).where(well_formed).rule(cin_to_scanf),
}


# Rule set "extended" (see c.c_extension_rules); operands of stream insertions belong to the iostream rules.
EXTENSION_RULES = c_extension_rules("cpp", (not_stream_operand,))

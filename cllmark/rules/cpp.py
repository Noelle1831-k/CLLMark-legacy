"""C++ rewrite rules: the C-family rules (C++ dialect) plus stdio <-> iostream rules."""

import re

from .c import (
    c_extension_rules,
    c_family_rules,
    file_fact,
    file_matches,
    is_snippet,
    no_type_keyword_macro,
    nodes,
    outside_text_sensitive_operands,
    subtree,
)
from .engine import Reject, guard, replace, text, well_formed

# ---------------------------------------------------------------- stdio <-> iostream (styles 9.1-9.4)
#
# Each direction only converts what the other direction writes back and what means the same in both: whole statements,
# specifiers without flags, width or precision, arguments whose type follows from a declaration in view. Files that
# rely on stream state (manipulators, tie, sync_with_stdio, other uses of cin) or redefine the I/O names are left alone.

SYNC_STDIO = re.compile(rb"\bsync_with_stdio\b|\b(?:cin|cout)\s*\.\s*tie\b")
IO_MACRO = re.compile(rb"^[ \t]*#[ \t]*define[ \t]+(?:cin|cout|printf|scanf|endl)\b", re.MULTILINE)
IOSTREAM_INCLUDE = re.compile(rb"^[ \t]*#[ \t]*include[ \t]*[<\"](?:iostream|bits/stdc\+\+\.h)[>\"]", re.MULTILINE)
STDIO_INCLUDE = re.compile(rb"^[ \t]*#[ \t]*include[ \t]*[<\"](?:cstdio|stdio\.h|bits/stdc\+\+\.h)[>\"]", re.MULTILINE)
USING_STD = re.compile(rb"\busing\s+namespace\s+std\s*;")
USING_ANY = re.compile(rb"\busing\s+namespace\b")
STREAM_FORMATTING = re.compile(
    rb"\b(?:setprecision|setw|setfill|setbase|setiosflags|resetiosflags)\b"
    rb"|<<\s*(?:std\s*::\s*)?(?:fixed|scientific|hex|oct|showbase|showpos|boolalpha|uppercase)\b"
    rb"|\.\s*(?:precision|width|fill|setf|unsetf|flags|imbue)\s*\("
)

# Declared type (one '*' per pointer or array level) -> the specifier cout/printf agree on, and the one scanf needs.
CANONICAL_TYPES = {
    "int": "int",
    "signed": "int",
    "signed int": "int",
    "short": "short",
    "short int": "short",
    "unsigned": "unsigned",
    "unsigned int": "unsigned",
    "long": "long",
    "long int": "long",
    "unsigned long": "unsigned long",
    "unsigned long int": "unsigned long",
    "long long": "long long",
    "long long int": "long long",
    "unsigned long long": "unsigned long long",
    "unsigned long long int": "unsigned long long",
    "char": "char",
    "double": "double",
    "float": "float",
    "string": "string",
}
OUTPUT_SPECIFIERS = {
    "int": "%d",
    "short": "%d",
    "unsigned": "%u",
    "long": "%ld",
    "long long": "%lld",
    "char": "%c",
    "char*": "%s",
    "string": "%s",
}  # no double/float: cout prints 6 significant digits, %f 6 decimals
INPUT_SPECIFIERS = {
    "int": "%d",
    "unsigned": "%u",
    "long": "%ld",
    "unsigned long": "%lu",
    "long long": "%lld",
    "unsigned long long": "%llu",
    "double": "%lf",
    "float": "%f",
    "char*": "%s",
}  # no short (%hd), char (scanf %c does not skip blanks), std::string or long double
STREAM_SPECIFIER = re.compile(r"%(?:lld|ld|[disuc])")
SCAN_FORMAT = re.compile(r"(?:\s|\\[nrt])*%(?:llu|lld|lu|ld|lf|[dufs])(?:(?:\s|\\[nrt])*%(?:llu|lld|lu|ld|lf|[dufs]))*")
SCAN_SPECIFIER = re.compile(r"%(?:llu|lld|lu|ld|lf|[dufs])")
INTEGER_LITERAL = re.compile(r"[1-9]\d{0,8}|0")


def declaration_names(declarator):
    names = set()
    for current in subtree(declarator):
        if current.type == "identifier":
            names.add(text(current))
    return names


def declarator_kind(declarator, base):
    """(name, kind) of a declarator: kind is `base` plus one '*' per pointer or array level, None when it is not
    told (references, functions, parenthesised declarators, an unknown base)."""
    levels, current = 0, declarator
    while current is not None:
        if current.type == "init_declarator":
            current = current.child_by_field_name("declarator")
        elif current.type in ["pointer_declarator", "array_declarator"]:
            levels += 1
            current = current.child_by_field_name("declarator")
        elif current.type == "identifier":
            return text(current), None if base is None else base + "*" * levels
        else:
            break
    names = sorted(declaration_names(declarator))
    return (names[0] if names else None), None


def declared_kinds(scope):
    """{name: kind} for the declarations directly in `scope` (kind None when the type cannot be told)."""
    kinds = {}
    for child in scope.children:
        if child.type != "declaration":
            continue
        kind = child.child_by_field_name("type")
        base = None
        if (
            kind is not None
            and child.children[0].id == kind.id
            and kind.type
            in [
                "primitive_type",
                "sized_type_specifier",
                "type_identifier",
            ]
        ):
            base = CANONICAL_TYPES.get(" ".join(text(kind).split()))
        for declarator in child.children_by_field_name("declarator"):
            name, described = declarator_kind(declarator, base)
            if name is not None:
                kinds[name] = described
    return kinds


def visible_kinds(node):
    """{name: kind} of the variables in view at `node`, innermost declaration first. Names that a loop header,
    a condition or a lambda declares are in the table with kind None: they hide outer declarations of the same name."""
    kinds = {}
    current = node.parent
    while current is not None:
        scope = {}
        if current.type == "compound_statement":
            scope = declared_kinds(current)
        elif current.type == "for_statement":
            scope = dict.fromkeys(declared_kinds(current))
        elif current.type == "for_range_loop":
            scope = dict.fromkeys(
                name
                for child in current.children
                if child.type not in ["compound_statement", "expression_statement"]
                for name in declaration_names(child)
            )
        elif current.type == "lambda_expression":
            body = current.child_by_field_name("body")
            scope = dict.fromkeys(
                name
                for child in current.children
                if body is None or child.id != body.id
                for name in declaration_names(child)
            )
        elif current.type in ["if_statement", "while_statement", "switch_statement"]:
            condition = current.child_by_field_name("condition")
            if condition is not None:
                scope = dict.fromkeys(
                    name
                    for part in subtree(condition)
                    if part.type == "declaration"
                    for name in declaration_names(part)
                )
        for name, kind in scope.items():
            kinds.setdefault(name, kind)
        current = current.parent
    return kinds


def promoted(kind):
    """The type of an arithmetic operand after the integer promotions (None for pointers, floats and strings)."""
    if kind in ["char", "short"]:
        return "int"
    return kind if kind in ["int", "unsigned", "long", "unsigned long", "long long", "unsigned long long"] else None


def expression_kind(node, kinds):
    """The canonical type of a plain expression (names, subscripts, integer literals, + - * / % of those), else None.

    Every form binds tighter than `<<`, so the text can stand as an operand of a stream chain unchanged."""
    if node.type == "identifier":
        return kinds.get(text(node))
    if node.type == "number_literal":
        return "int" if INTEGER_LITERAL.fullmatch(text(node)) else None
    if node.type == "char_literal":
        return "char" if text(node).startswith("'") else None
    if node.type == "string_literal":
        return "char*" if text(node).startswith('"') else None
    if node.type == "parenthesized_expression" and len(node.children) == 3:
        return expression_kind(node.children[1], kinds)
    if node.type == "subscript_expression":
        base = expression_kind(node.child_by_field_name("argument"), kinds)
        return base[:-1] if base is not None and base.endswith("*") else None
    if node.type == "unary_expression" and len(node.children) == 2 and text(node.children[0]) in ["-", "+"]:
        return promoted(expression_kind(node.children[1], kinds))
    if node.type == "binary_expression" and len(node.children) == 3 and text(node.children[1]) in "+-*/%":
        left = promoted(expression_kind(node.children[0], kinds))
        right = promoted(expression_kind(node.children[2], kinds))
        if left is None or right is None:
            return None
        if left == right or right == "int":
            return left
        return right if left == "int" else None
    return None


def lvalue_path(node):
    """`name`, `name[index]...` or `name.field...`."""
    if node.type == "identifier":
        return True
    if node.type == "subscript_expression":
        return lvalue_path(node.child_by_field_name("argument"))
    if node.type == "field_expression" and len(node.children) == 3 and node.children[1].type == ".":
        return lvalue_path(node.children[0])
    return False


def stream_items(node, stream, operator):
    """The operands of `stream << a << b;` (or `>>`) as nodes, None when the statement is anything else."""
    if node.child_count != 2 or node.children[1].type != ";":
        return None
    items, current = [], node.children[0]
    while current.type == "binary_expression":
        if len(current.children) != 3 or text(current.children[1]) != operator:
            return None
        items.insert(0, current.children[2])
        current = current.children[0]
    if current.type != "identifier" or text(current) != stream or not items:
        return None
    return items


def literal_content(node):
    """The raw text between the quotes of a plain string literal (escapes untouched), None for prefixed ones."""
    value = text(node)
    return value[1:-1] if node.type == "string_literal" and value.startswith('"') and value.endswith('"') else None


def call_values(node):
    """The arguments of a call as nodes without comments."""
    arguments = node.child_by_field_name("arguments")
    return None if arguments is None else [child for child in arguments.named_children if child.type != "comment"]


def printf_operands(node):
    """printf("a %d b", x) -> ['"a "', 'x', '" b"'] (the operands after `cout <<`), None when it is not convertible."""
    values = call_values(node)
    if not values:
        return None
    content = literal_content(values[0])
    if content is None or content.count("%") != len(STREAM_SPECIFIER.findall(content)):
        return None  # a flag, width, precision, float or other specifier, or %%
    matches = list(STREAM_SPECIFIER.finditer(content))
    if len(matches) != len(values) - 1:
        return None
    kinds = visible_kinds(node)
    operands, position = [], 0
    for match, value in zip(matches, values[1:], strict=True):
        specifier = "%d" if match.group() == "%i" else match.group()
        piece = content[position : match.start()]
        operands += [f'"{piece}"'] if piece else []
        if (
            value.type == "call_expression"
            and text(value.child_by_field_name("function")).endswith(".c_str")
            and not call_values(value)
        ):
            target = value.child_by_field_name("function").children[0]
            if target.type != "identifier" or kinds.get(text(target)) != "string" or specifier != "%s":
                return None
            operands.append(text(target))
        else:
            if OUTPUT_SPECIFIERS.get(expression_kind(value, kinds)) != specifier:
                return None
            operands.append(text(value))
        position = match.end()
    if content[position:]:
        operands.append(f'"{content[position:]}"')
    return operands or None


def cout_format(node):
    """cout << a << "x" << endl; -> (format, [arguments]) for printf, None when some operand is not convertible."""
    items = stream_items(node, "cout", "<<")
    if items is None:
        return None
    kinds = visible_kinds(node)
    format_text, arguments = "", []
    for item in items:
        content = literal_content(item)
        if content is not None:
            if "%" in content:
                return None
            format_text += content
        elif item.type == "identifier" and text(item) == "endl" and "endl" not in kinds:
            format_text += "\\n"
        else:
            kind = expression_kind(item, kinds)
            specifier = OUTPUT_SPECIFIERS.get(kind)
            if specifier is None:
                return None
            format_text += specifier
            arguments.append(text(item) + (".c_str()" if kind == "string" else ""))
    return (format_text, arguments) if format_text or arguments else None


def scanf_operands(node):
    """scanf("%d %d", &a, &b) -> ['a', 'b'] (the operands after `cin >>`), None when it is not convertible.

    Each argument must be a name, element or member whose declared type is the one the specifier reads (the type table
    of cin -> scanf), so that the conversion back writes the same specifier."""
    values = call_values(node)
    if not values:
        return None
    content = literal_content(values[0])
    if content is None or not SCAN_FORMAT.fullmatch(content):
        return None  # other text, %c, %[, a width, %*, %i, or trailing blanks (scanf would consume them)
    specifiers = SCAN_SPECIFIER.findall(content)
    if len(specifiers) != len(values) - 1:
        return None
    kinds = visible_kinds(node)
    operands = []
    for specifier, value in zip(specifiers, values[1:], strict=True):
        if specifier == "%s":
            target = value if value.type == "identifier" else None
        else:
            target = value.child_by_field_name("argument") if value.type == "pointer_expression" else None
            if target is not None and (text(value.children[0]) != "&" or not lvalue_path(target)):
                target = None
        if target is None or INPUT_SPECIFIERS.get(expression_kind(target, kinds)) != specifier:
            return None
        operands.append(text(target))
    return operands


def cin_format(node):
    """cin >> a >> b; -> (format, [arguments]) for scanf, None when some operand is not convertible."""
    items = stream_items(node, "cin", ">>")
    if items is None:
        return None
    kinds = visible_kinds(node)
    format_text, arguments = "", []
    for item in items:
        if item.type not in ["identifier", "subscript_expression"]:
            return None
        kind = expression_kind(item, kinds)
        specifier = INPUT_SPECIFIERS.get(kind)
        if specifier is None:
            return None
        format_text += specifier
        arguments.append(text(item) if kind == "char*" else "&" + text(item))
    return format_text, arguments


@guard("no sync_with_stdio or tie (mixing the two libraries then reorders or loses input)")
def synchronized_streams(node):
    return not file_matches(node, "sync", SYNC_STDIO)


@guard("cin, cout, printf, scanf and endl are not macros")
def plain_io_names(node):
    return not file_matches(node, "io macro", IO_MACRO)


@guard("iostream is included and std is in use (the rewrite writes cin / cout unqualified)")
def iostream_available(node):
    """Both directions need it, so that each can undo the other. A file without any #include or using-directive is a
    fragment whose headers and `using namespace std;` come from the harness around it."""
    snippet = is_snippet(node)
    included = snippet or file_matches(node, "iostream", IOSTREAM_INCLUDE)
    in_use = file_matches(node, "using std", USING_STD) or (snippet and not file_matches(node, "using", USING_ANY))
    return included and in_use


@guard("stdio is included (printf and scanf are declared)")
def stdio_available(node):
    """Needed in all four rules, so that each direction can undo the other; fragments get their headers from the
    harness (see iostream_available)."""
    return is_snippet(node) or file_matches(node, "stdio", STDIO_INCLUDE)


@guard("the file sets no stream formatting (precision, width, base)")
def default_stream_format(node):
    return not file_matches(node, "formatting", STREAM_FORMATTING)


def stray_cin(root):
    """`cin` occurs somewhere other than as the head of a `cin >> ...;` statement (`while (cin >> n)`, `cin.eof()`)."""
    if b"cin" not in root.text:
        return False
    names = heads = 0
    for current in subtree(root):
        if current.type == "identifier" and current.text == b"cin":
            names += 1
        elif current.type == "expression_statement" and stream_items(current, "cin", ">>") is not None:
            heads += 1
    return names != heads


@guard("every cin of the file heads a `cin >> ...;` statement")
def cin_only_in_statements(node):
    return not file_fact(node, "stray cin", stray_cin)


@guard("the call's value is unused (a statement)")
def call_statement(node):
    return node.parent is not None and node.parent.type == "expression_statement"


def convertible(function):
    return guard(f"convertible by {function.__name__}")(lambda node: function(node) is not None)


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
    operands = printf_operands(node)
    if operands is None:
        raise Reject("not convertible")
    return [replace(node, " << ".join(["cout", *operands]))]


def cout_to_printf(node, source):
    converted = cout_format(node)
    if converted is None:
        raise Reject("operand type unknown")
    format_text, arguments = converted
    return [replace(node, "".join([f'printf("{format_text}"', *(f", {argument}" for argument in arguments), ");"]))]


def scanf_to_cin(node, source):
    """scanf("%d", &x) -> cin >> x"""
    operands = scanf_operands(node)
    if operands is None:
        raise Reject("not convertible")
    return [replace(node, " >> ".join(["cin", *operands]))]


def cin_to_scanf(node, source):
    converted = cin_format(node)
    if converted is None:
        raise Reject("operand type unknown")
    format_text, arguments = converted
    return [replace(node, "".join([f'scanf("{format_text}"', *(f", {argument}" for argument in arguments), ");"]))]


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


@guard("not at the start of a statement (`void(x);` and `int(x);` declare x)")
def not_statement_start(node):
    """`(void)x;` -> `void(x);` would be the declaration of a variable x (the most vexing parse); so would any `T(x)`
    that starts an expression statement."""
    current = node
    while current.parent is not None and current.parent.start_byte == node.start_byte:
        current = current.parent
        if current.type in ["expression_statement", "declaration", "for_statement", "condition_clause"]:
            return False
    return True


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
    .where(
        c_style_cast, not_stream_operand, not_statement_start, outside_text_sensitive_operands, no_type_keyword_macro
    )
    .where(well_formed)
    .rule(to_functional_cast),
    "22.2": nodes("call_expression")
    .where(functional_cast, not_stream_operand, outside_text_sensitive_operands, no_type_keyword_macro)
    .where(well_formed)
    .rule(to_c_style_cast),
    "9.1": call_to("printf")
    .where(
        call_statement,
        no_type_keyword_macro,
        synchronized_streams,
        plain_io_names,
        iostream_available,
        default_stream_format,
        stdio_available,
        convertible(printf_operands),
    )
    .where(well_formed)
    .rule(printf_to_cout),
    "9.2": nodes("expression_statement")
    .where(
        no_type_keyword_macro,
        synchronized_streams,
        plain_io_names,
        iostream_available,
        default_stream_format,
        stdio_available,
        convertible(cout_format),
    )
    .where(well_formed)
    .rule(cout_to_printf),
    "9.3": call_to("scanf")
    .where(
        call_statement,
        no_type_keyword_macro,
        synchronized_streams,
        plain_io_names,
        iostream_available,
        cin_only_in_statements,
        stdio_available,
        convertible(scanf_operands),
    )
    .where(well_formed)
    .rule(scanf_to_cin),
    "9.4": nodes("expression_statement")
    .where(
        no_type_keyword_macro,
        synchronized_streams,
        plain_io_names,
        iostream_available,
        cin_only_in_statements,
        stdio_available,
        convertible(cin_format),
    )
    .where(well_formed)
    .rule(cin_to_scanf),
}


# Rule set "extended" (see c.c_extension_rules); operands of stream insertions belong to the iostream rules.
EXTENSION_RULES = c_extension_rules("cpp", (not_stream_operand,))

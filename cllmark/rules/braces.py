"""Braces around a loop body of one simple statement (extension pair "loop_braces", C++ range-for and JavaScript).

Two layouts, each an exact inverse of the other direction:

    for (...) S;            <->  for (...) { S; }
    for (...)                    for (...) {
        S;                  <->      S;
                                 }

The closing brace takes the indentation of the line the loop starts on. `same_line_only` loop types (JavaScript for and
while, whose header the loop-form rules 7.x read as `while (c) `) take only the first layout. S is one single-line expression, return,
break or continue statement that ends its line; no comment may sit between the tokens that move. A body of any other
shape is not a candidate of either direction.
"""

from .engine import Edit

SIMPLE_STATEMENTS = ["expression_statement", "return_statement", "break_statement", "continue_statement"]


def _file(node):
    root = node
    while root.parent is not None:
        root = root.parent
    return root.text, root.start_byte


def _ends_line(data, base, end):
    return end - base >= len(data) or data[end - base : end - base + 1] in (b"\n", b"\r")


def _line_indent(data, base, position):
    """Leading whitespace of the line holding `position`."""
    start = data.rfind(b"\n", 0, position - base) + 1
    line = data[start : position - base]
    return line[: len(line) - len(line.lstrip(b" \t"))]


def _simple(statement):
    return statement.type in SIMPLE_STATEMENTS and b"\n" not in statement.text


def _head_end(loop, body):
    """End of the loop header: its `)` (for loops) or its parenthesized condition (while loops)."""
    before = body.prev_sibling
    return before.end_byte if before is not None and before.type in [")", "parenthesized_expression"] else None


def bare_layout(loop, same_line_only=()):
    """("same_line" | "next_line", body) for a brace-less simple body, else None."""
    body = loop.child_by_field_name("body")
    if body is None or not _simple(body):
        return None
    head = _head_end(loop, body)
    if head is None:
        return None
    data, base = _file(loop)
    if not _ends_line(data, base, body.end_byte):
        return None
    gap = data[head - base : body.start_byte - base]
    if gap == b" ":
        return "same_line", body
    if loop.type in same_line_only:
        return None
    if gap[:1] == b"\n" and not gap[1:].strip(b" \t") and gap[1:] == _line_indent(data, base, body.start_byte):
        return "next_line", body
    return None


def braced_layout(loop, block_type, same_line_only=()):
    """("same_line" | "next_line", block, statement) for a braced simple body in one of the two layouts, else None."""
    block = loop.child_by_field_name("body")
    if block is None or block.type != block_type or len(block.children) != 3:
        return None
    statement = block.children[1]
    if not _simple(statement) or block.children[0].type != "{" or block.children[2].type != "}":
        return None
    head = _head_end(loop, block)
    if head is None:
        return None
    data, base = _file(loop)
    if data[head - base : block.start_byte - base] != b" " or not _ends_line(data, base, block.end_byte):
        return None
    if block.text == b"{ " + statement.text + b" }":
        return "same_line", block, statement
    if loop.type in same_line_only:
        return None
    opening = data[block.start_byte - base : statement.start_byte - base]
    closing = data[statement.end_byte - base : block.end_byte - base]
    indent = _line_indent(data, base, statement.start_byte)
    if opening == b"{\n" + indent and closing == b"\n" + _line_indent(data, base, loop.start_byte) + b"}":
        return "next_line", block, statement
    return None


def add_braces(loop, source):
    layout, body = bare_layout(loop)  # the guard has checked the layout against same_line_only
    if layout == "same_line":
        return [Edit(body.start_byte, body.start_byte, "{ "), Edit(body.end_byte, body.end_byte, " }")]
    data, base = _file(loop)
    head = _head_end(loop, body)
    closing = "\n" + _line_indent(data, base, loop.start_byte).decode("utf-8") + "}"
    return [Edit(head, head, " {"), Edit(body.end_byte, body.end_byte, closing)]


def drop_braces(block_type):
    def rewrite(loop, source):
        layout, block, statement = braced_layout(loop, block_type)
        if layout == "same_line":
            return [Edit(block.start_byte, statement.start_byte, ""), Edit(statement.end_byte, block.end_byte, "")]
        data, base = _file(loop)
        indent = _line_indent(data, base, statement.start_byte).decode("utf-8")
        return [
            Edit(_head_end(loop, block), statement.start_byte, "\n" + indent),
            Edit(statement.end_byte, block.end_byte, ""),
        ]

    return rewrite

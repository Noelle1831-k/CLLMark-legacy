"""JavaScript rewrite rules, keyed by style id (see styleList.json).

Families follow the C rules where JavaScript has the same construct (2.x operators,
3.x updates, 6.x declarations, 7.x loops, 14-19 control flow and member access); 23.x is
JavaScript-specific. Every rewrite is exact under JavaScript semantics:

* operand order only changes when the moved operands are literals or plain identifiers,
  so no getter, valueOf or call can observe a different evaluation order;
* negations wrap the whole test in !( ), which is the ToBoolean negation `if`/`?:` use;
* rules stay out of the operands of equality tests that the hash-order rules read.
"""

import hashlib
import re

from rule_engine import Edit, Matcher, Reject, delete_between, guard, insert_after, replace, text, well_formed


def nodes(node_type):
    return Matcher(f'(({node_type}) @node)')


def operator(node):
    return text(node.child_by_field_name('operator'))


EQUALITY = ['===', '==', '!==', '!=']
POSITIVE = {'===': '!==', '==': '!='}
NEGATIVE = {'!==': '===', '!=': '=='}
RELATIONAL = ['<', '<=', '>', '>=']
LITERALS = ['number', 'string']
SIMPLE = ['identifier', 'number', 'string', 'true', 'false', 'null', 'undefined']
LOOSER_THAN_RELATIONAL = RELATIONAL + EQUALITY + ['&&', '||', '??', '&', '|', '^', 'in', 'instanceof']
BINARY = nodes('binary_expression')


def is_equality(node):
    return node.type == 'binary_expression' and operator(node) in EQUALITY


@guard('directly inside !(...)')
def negated(node):
    parent = node.parent
    return parent is not None and parent.type == 'parenthesized_expression' and len(parent.children) == 3 \
        and parent.parent is not None and parent.parent.type == 'unary_expression' and operator(parent.parent) == '!'


@guard('outside equality operands')
def outside_equality_operands(node):
    parent = node.parent
    while parent is not None and not parent.type.endswith(('statement', 'declaration', 'declarator')):
        if is_equality(parent):
            return False
        parent = parent.parent
    return True


def operator_in(*operators):
    return guard('operator ' + '|'.join(operators))(lambda node: operator(node) in operators)


# ---------------------------------------------------------------- 2.x equality, relational and assignment

def negate_equality(node, source):
    """a === b -> !(a !== b)"""
    left, right = node.child_by_field_name('left'), node.child_by_field_name('right')
    return [replace(node, f'!({text(left)} {POSITIVE.get(operator(node)) or NEGATIVE[operator(node)]} {text(right)})')]


def negated_test(operators):
    """!(a <op> b)"""
    def test(node):
        if operator(node) != '!':
            return False
        group = node.child_by_field_name('argument')
        return group.type == 'parenthesized_expression' and len(group.children) == 3 and group.children[1].type == 'binary_expression' \
            and operator(group.children[1]) in operators
    return nodes('unary_expression').where(guard('!(a ' + '|'.join(operators) + ' b)')(test))


def remove_negation(node, source):
    """!(a !== b) -> a === b"""
    inner = node.child_by_field_name('argument').children[1]
    flipped = POSITIVE.get(operator(inner)) or NEGATIVE[operator(inner)]
    return [replace(node, f'{text(inner.child_by_field_name("left"))} {flipped} {text(inner.child_by_field_name("right"))}')]


MIRROR = {'<': '>', '<=': '>=', '>': '<', '>=': '<='}


def literal_comparison(literal_on_left):
    """A relational test with exactly one literal operand, on the given side."""
    def test(node):
        left, right = node.child_by_field_name('left'), node.child_by_field_name('right')
        if any(side.type == 'binary_expression' and operator(side) in LOOSER_THAN_RELATIONAL for side in [left, right]):
            return False
        literal, other = (left, right) if literal_on_left else (right, left)
        return literal.type in LITERALS and other.type not in LITERALS
    return BINARY.where(operator_in(*RELATIONAL), guard('literal on the ' + ('left' if literal_on_left else 'right'))(test))


def mirror(node, source):
    """x > 0 -> 0 < x (the literal has no side effects, so evaluation order is unobservable)"""
    left, right = node.child_by_field_name('left'), node.child_by_field_name('right')
    return [replace(node, f'{text(right)} {MIRROR[operator(node)]} {text(left)}')]


def hash_at_least(left, right):
    return int(hashlib.sha256(left.encode('utf-8')).hexdigest(), 16) >= int(hashlib.sha256(right.encode('utf-8')).hexdigest(), 16)


def hash_order(equality_rule, swap_when_left_hash_larger):
    """a === b -> b === a following the operands' SHA-256 order (equality is symmetric).

    As in the C and Python rules, the equality rule owns === / == outside !( ) and
    !== / != inside it; the inequality rule owns the other two cases.
    """
    def rewrite(node, source):
        positive = operator(node) in POSITIVE
        if (positive != negated(node)) != equality_rule:
            raise Reject('other operator')
        left, right = text(node.child_by_field_name('left')), text(node.child_by_field_name('right'))
        if hash_at_least(left, right) != swap_when_left_hash_larger:
            raise Reject('already in order')
        return [replace(node, f'{right} {operator(node)} {left}')]
    return rewrite


SIMPLE_EQUALITY = BINARY.where(operator_in(*EQUALITY), guard('identifier/literal operands')(
    lambda node: node.child_by_field_name('left').type in SIMPLE and node.child_by_field_name('right').type in SIMPLE))
COMPOUND = ['+', '-', '*', '/', '%', '**', '<<', '>>', '>>>', '&', '|', '^']
OPERAND = SIMPLE + ['member_expression', 'subscript_expression', 'call_expression', 'parenthesized_expression', 'unary_expression']


@guard('x = x <op> y with a plain y')
def self_assignment(node):
    target, value = node.child_by_field_name('left'), node.child_by_field_name('right')
    return target.type == 'identifier' and value.type == 'binary_expression' and operator(value) in COMPOUND \
        and text(value.child_by_field_name('left')) == text(target) and value.child_by_field_name('right').type in OPERAND


@guard('x <op>= y with a plain y')
def compound_assignment(node):
    return node.child_by_field_name('left').type == 'identifier' and operator(node)[:-1] in COMPOUND \
        and node.child_by_field_name('right').type in OPERAND


def to_compound(node, source):
    """x = x + y -> x += y"""
    value = node.child_by_field_name('right')
    return [replace(node, f'{text(node.child_by_field_name("left"))} {operator(value)}= {text(value.child_by_field_name("right"))}')]


def from_compound(node, source):
    """x += y -> x = x + y"""
    target = text(node.child_by_field_name('left'))
    return [replace(node, f'{target} = {target} {operator(node)[:-1]} {text(node.child_by_field_name("right"))}')]


# ---------------------------------------------------------------- 3.x ++ / --

@guard('value unused (statement or for-update)')
def value_unused(node):
    parent = node.parent
    return parent.type == 'expression_statement' or (parent.type == 'for_statement' and parent.child_by_field_name('increment') == node)


def prefix_form(prefix):
    return guard('prefix ++/--' if prefix else 'postfix ++/--')(lambda node: node.children[0].type in ['++', '--'] if prefix else node.children[1].type in ['++', '--'])


def flip_update(node, source):
    """i++ -> ++i (and back)"""
    first, second = node.children
    return [replace(node, text(second) + text(first))]


# ---------------------------------------------------------------- 6.x declarations

def keyword(declaration):
    return text(declaration.children[0])


def declarators(declaration):
    return [child for child in declaration.children if child.type == 'variable_declarator']


@guard('declares several names in a block')
def multi_declaration(node):
    return node.parent.type in ['program', 'statement_block'] and len(declarators(node)) > 1 \
        and [child.type for child in node.children if child.type not in ['variable_declarator', ',']] in [[keyword(node), ';'], [keyword(node)]] \
        and node.children[-1].type == ';'


def split_declaration(node, source):
    """let a = 1, b = 2; -> let a = 1; / let b = 2;"""
    indent = source.leading(node)
    if indent is None:
        raise Reject('declaration shares its line')
    kind = keyword(node)
    return [replace(node, f'\n{indent}'.join(f'{kind} {text(item)};' for item in declarators(node)))]


def declaration_run(node):
    """The run of single-name declarations of one kind starting at `node`, separated only by line breaks."""
    run = [node]
    while True:
        following = run[-1].next_sibling
        if following is None or following.type != node.type or keyword(following) != keyword(node) or len(declarators(following)) != 1 \
                or following.children[-1].type != ';' or following.start_point[0] != run[-1].end_point[0] + 1:
            return run
        run.append(following)


@guard('first of consecutive single-name declarations of one kind')
def declaration_run_start(node):
    if node.parent.type not in ['program', 'statement_block'] or len(declarators(node)) != 1 or node.children[-1].type != ';':
        return False
    previous = node.prev_sibling
    if previous is not None and previous.type == node.type and keyword(previous) == keyword(node) and len(declarators(previous)) == 1 \
            and previous.children[-1].type == ';' and node.start_point[0] == previous.end_point[0] + 1:
        return False
    return len(declaration_run(node)) > 1


def merge_declarations(node, source):
    """let a = 1; / let b = 2; -> let a = 1, b = 2;"""
    run = declaration_run(node)
    indent = source.leading(node)
    if indent is None or any(source.leading(item) != indent for item in run):
        raise Reject('irregular layout')
    merged = f'{keyword(node)} ' + ', '.join(text(declarators(item)[0]) for item in run) + ';'
    return [Edit(node.start_byte, run[-1].end_byte, merged)]


# ---------------------------------------------------------------- 7.x while / for(;;)

@guard('for (; c; ) without init or update')
def condition_only_for(node):
    return node.child_by_field_name('increment') is None and node.children[2].type == 'empty_statement' \
        and node.children[3].type == 'expression_statement' and node.children[3].children[-1].type == ';'


def for_to_while(node, source):
    """for (; c; ) S -> while (c) S"""
    condition = node.children[3].children[0]
    return [Edit(node.start_byte, node.child_by_field_name('body').start_byte, f'while ({text(condition)}) ')]


def while_to_for(node, source):
    """while (c) S -> for (; c; ) S"""
    condition = node.child_by_field_name('condition')
    if len(condition.children) != 3 or condition.children[1].type == 'sequence_expression':
        raise Reject('irregular condition')
    return [Edit(node.start_byte, node.child_by_field_name('body').start_byte, f'for (; {text(condition.children[1])}; ) ')]


# ---------------------------------------------------------------- 14-16 branches and conditions

def negated_group(node):
    return node.type == 'unary_expression' and operator(node) == '!' and node.child_by_field_name('argument').type == 'parenthesized_expression' \
        and len(node.child_by_field_name('argument').children) == 3


def negatable(expression):
    return not is_equality(expression) and not negated_group(expression) and expression.type not in ['sequence_expression', 'assignment_expression']


def statements(block):
    return [child for child in block.children[1:-1] if child.type != 'comment']


def condition_value(statement):
    group = statement.child_by_field_name('condition')
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
    return node.type == 'if_statement' and node.child_by_field_name('alternative') is not None


def braced_if_else(negated_form):
    """if (c) { A } else { B } (or the !(c) form); blocks holding another if/else are left alone
    so that nested candidates never overlap."""
    def test(node):
        value, clause = condition_value(node), node.child_by_field_name('alternative')
        consequence = node.child_by_field_name('consequence')
        if value is None or clause is None or consequence.type != 'statement_block':
            return False
        branch = [child for child in clause.children if child.is_named]
        if len(branch) != 1 or branch[0].type != 'statement_block' or contains(consequence, has_else) or contains(branch[0], has_else):
            return False
        return negated_group(value) and negatable(value.child_by_field_name('argument').children[1]) if negated_form else negatable(value)
    return nodes('if_statement').where(guard('if (!(c)) {..} else {..}' if negated_form else 'if (c) {..} else {..}')(test))


def swap_branches(negate):
    """if (c) { A } else { B } -> if (!(c)) { B } else { A }   (and back)"""
    def rewrite(node, source):
        value = condition_value(node)
        consequence = node.child_by_field_name('consequence')
        alternative = [child for child in node.child_by_field_name('alternative').children if child.is_named][0]
        flipped = f'!({text(value)})' if negate else text(value.child_by_field_name('argument').children[1])
        return [replace(value, flipped), replace(consequence, text(alternative)), replace(alternative, text(consequence))]
    return rewrite


def movable_conditional(negated_form):
    def test(node):
        condition = node.child_by_field_name('condition')
        if any(node.child_by_field_name(field).type == 'sequence_expression' for field in ['consequence', 'alternative']):
            return False
        if contains(node, lambda child: child.type == 'ternary_expression'):
            return False
        return negated_group(condition) and negatable(condition.child_by_field_name('argument').children[1]) if negated_form else negatable(condition)
    return nodes('ternary_expression').where(guard('!(c) ? a : b' if negated_form else 'c ? a : b')(test), outside_equality_operands)


def swap_conditional(negate):
    """c ? a : b -> !(c) ? b : a   (and back; the operands trade places, layout kept)"""
    def rewrite(node, source):
        condition = node.child_by_field_name('condition')
        a, b = node.child_by_field_name('consequence'), node.child_by_field_name('alternative')
        flipped = f'!({text(condition)})' if negate else text(condition.child_by_field_name('argument').children[1])
        return [replace(condition, flipped), replace(a, text(b)), replace(b, text(a))]
    return rewrite


def conjunct(node):
    return node.type not in ['sequence_expression', 'assignment_expression', 'augmented_assignment_expression', 'ternary_expression',
                             'arrow_function', 'yield_expression'] \
        and not (node.type == 'binary_expression' and operator(node) in ['&&', '||', '??'])


@guard('if (a && b) { S } without else')
def conjunctive_if(node):
    value, consequence = condition_value(node), node.child_by_field_name('consequence')
    if value is None or node.child_by_field_name('alternative') is not None or consequence.type != 'statement_block':
        return False
    left, right = value.child_by_field_name('left'), value.child_by_field_name('right')
    return value.type == 'binary_expression' and operator(value) == '&&' and conjunct(left) and conjunct(right) \
        and value.text[left.end_byte - value.start_byte:right.start_byte - value.start_byte] == b' && '


@guard('if (a) if (b) { S } without else')
def nested_if(node):
    consequence = node.child_by_field_name('consequence')
    if condition_value(node) is None or node.child_by_field_name('alternative') is not None or consequence.type != 'if_statement' \
            or consequence.child_by_field_name('alternative') is not None:
        return False
    body = consequence.child_by_field_name('consequence')
    inner, outer = condition_value(consequence), condition_value(node)
    return inner is not None and body.type == 'statement_block' and conjunct(outer) and conjunct(inner) \
        and node.text[outer.end_byte - node.start_byte:inner.start_byte - node.start_byte] == b') if ('


def split_conjunction(node, source):
    """if (a && b) { S } -> if (a) if (b) { S }"""
    value = condition_value(node)
    return [Edit(value.child_by_field_name('left').end_byte, value.child_by_field_name('right').start_byte, ') if (')]


def join_conjunction(node, source):
    """if (a) if (b) { S } -> if (a && b) { S }"""
    return [Edit(condition_value(node).end_byte, condition_value(node.child_by_field_name('consequence')).start_byte, ' && ')]


# ---------------------------------------------------------------- 18 final return in functions

FUNCTIONS = '[(function_declaration) (function) (generator_function_declaration) (generator_function) (method_definition) (arrow_function)] @node'


def function_body(node):
    body = node.child_by_field_name('body')
    return body if body is not None and body.type == 'statement_block' else None


@guard('function body ending with return;')
def ends_with_bare_return(node):
    body = function_body(node)
    items = statements(body) if body else []
    return len(items) >= 2 and items[-1].type == 'return_statement' and [child.type for child in items[-1].children] in [['return', ';'], ['return']]


@guard('non-empty function body without a final return')
def ends_without_return(node):
    body = function_body(node)
    items = statements(body) if body else []
    return bool(items) and items[-1].type != 'return_statement'


def add_final_return(node, source):
    """function f() { ...; } -> function f() { ...; return; }"""
    last = statements(function_body(node))[-1]
    indent = source.leading(last)
    if indent is None:
        raise Reject('last statement shares its line')
    return [insert_after(last, f'\n{indent}return;')]


def drop_final_return(node, source):
    """function f() { ...; return; } -> function f() { ...; }"""
    final = statements(function_body(node))[-1]
    return [delete_between(final.prev_sibling.end_byte, final.end_byte)]


# ---------------------------------------------------------------- 19 member access

IDENTIFIER_NAME = re.compile(r'^[A-Za-z_$][A-Za-z0-9_$]*$')


@guard('o.name (no optional chaining or private name)')
def dot_access(node):
    field = node.child_by_field_name('property')
    return field is not None and field.type == 'property_identifier' and not any(child.type == 'optional_chain' for child in node.children) \
        and text(node.children[1]) == '.'


@guard('o["name"] with an identifier-like double-quoted name')
def bracket_access(node):
    index = node.child_by_field_name('index')
    return index is not None and index.type == 'string' and len(index.children) == 3 and text(index)[0] == '"' \
        and IDENTIFIER_NAME.match(text(index)[1:-1]) is not None and not any(child.type == 'optional_chain' for child in node.children)


def to_bracket(node, source):
    """o.name -> o["name"]  (only the accessor changes, so accesses nested in o are independent edits)"""
    return [Edit(node.child_by_field_name('object').end_byte, node.end_byte, f'["{text(node.child_by_field_name("property"))}"]')]


def to_dot(node, source):
    """o["name"] -> o.name"""
    return [Edit(node.child_by_field_name('object').end_byte, node.end_byte, '.' + text(node.child_by_field_name('index'))[1:-1])]


# ---------------------------------------------------------------- 23 property shorthand

@guard('{ a: a } with a plain identifier key and value')
def explicit_property(node):
    key, value = node.child_by_field_name('key'), node.child_by_field_name('value')
    return node.parent.type == 'object' and key.type == 'property_identifier' and value.type == 'identifier' \
        and text(key) == text(value) and text(key) != '__proto__'


@guard('{ a } in an object literal')
def shorthand_property(node):
    return node.parent.type == 'object' and text(node) != '__proto__'


# ---------------------------------------------------------------- registry

EQUALITY_TEST = BINARY.where(operator_in(*EQUALITY), outside_equality_operands)
POSITIVE_TEST = EQUALITY_TEST.where(operator_in('===', '=='), ~negated)
NEGATIVE_TEST = EQUALITY_TEST.where(operator_in('!==', '!='), ~negated)
UPDATE = nodes('update_expression').where(value_unused)

RULES = {
    '2.1': nodes('assignment_expression').where(self_assignment).where(well_formed).rule(to_compound),
    '2.2': nodes('augmented_assignment_expression').where(compound_assignment).where(well_formed).rule(from_compound),
    '2.3': POSITIVE_TEST.where(well_formed).rule(negate_equality),
    '2.4': negated_test(['!==', '!=']).where(well_formed).rule(remove_negation),
    '2.5': NEGATIVE_TEST.where(well_formed).rule(negate_equality),
    '2.6': negated_test(['===', '==']).where(well_formed).rule(remove_negation),
    '2.7': literal_comparison(literal_on_left=True).where(outside_equality_operands).where(well_formed).rule(mirror),
    '2.8': literal_comparison(literal_on_left=False).where(outside_equality_operands).where(well_formed).rule(mirror),
    '2.11': SIMPLE_EQUALITY.where(well_formed).rule(hash_order(equality_rule=True, swap_when_left_hash_larger=True)),
    '2.12': SIMPLE_EQUALITY.where(well_formed).rule(hash_order(equality_rule=True, swap_when_left_hash_larger=False)),
    '2.13': SIMPLE_EQUALITY.where(well_formed).rule(hash_order(equality_rule=False, swap_when_left_hash_larger=True)),
    '2.14': SIMPLE_EQUALITY.where(well_formed).rule(hash_order(equality_rule=False, swap_when_left_hash_larger=False)),
    '3.1': UPDATE.where(prefix_form(False)).where(well_formed).rule(flip_update),
    '3.2': UPDATE.where(prefix_form(True)).where(well_formed).rule(flip_update),
    '6.1': Matcher('[(lexical_declaration) (variable_declaration)] @node').where(multi_declaration).where(well_formed).rule(split_declaration),
    '6.2': Matcher('[(lexical_declaration) (variable_declaration)] @node').where(declaration_run_start).where(well_formed).rule(merge_declarations),
    '7.1': nodes('for_statement').where(condition_only_for).where(well_formed).rule(for_to_while),
    '7.2': nodes('while_statement').where(well_formed).rule(while_to_for),
    '14.1': braced_if_else(negated_form=True).where(well_formed).rule(swap_branches(negate=False)),
    '14.2': braced_if_else(negated_form=False).where(well_formed).rule(swap_branches(negate=True)),
    '15.1': movable_conditional(negated_form=True).where(well_formed).rule(swap_conditional(negate=False)),
    '15.2': movable_conditional(negated_form=False).where(well_formed).rule(swap_conditional(negate=True)),
    '16.1': nodes('if_statement').where(nested_if).where(well_formed).rule(join_conjunction),
    '16.2': nodes('if_statement').where(conjunctive_if).where(well_formed).rule(split_conjunction),
    '18.1': Matcher(FUNCTIONS).where(ends_with_bare_return).where(well_formed).rule(drop_final_return),
    '18.2': Matcher(FUNCTIONS).where(ends_without_return).where(well_formed).rule(add_final_return),
    '19.1': nodes('subscript_expression').where(bracket_access, outside_equality_operands).where(well_formed).rule(to_dot),
    '19.2': nodes('member_expression').where(dot_access, outside_equality_operands).where(well_formed).rule(to_bracket),
    '23.1': nodes('pair').where(explicit_property, outside_equality_operands).where(well_formed).rule(lambda node, source: [replace(node, text(node.child_by_field_name('key')))]),
    '23.2': nodes('shorthand_property_identifier').where(shorthand_property, outside_equality_operands).where(well_formed).rule(
        lambda node, source: [replace(node, f'{text(node)}: {text(node)}')]),
}


# ---------------------------------------------------------------- function extraction

FUNCTION = nodes('function_declaration')


def function_name(node):
    return text(node.child_by_field_name('name'))

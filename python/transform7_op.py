import hashlib
from typing import List, Tuple, Union

import networkx as nx
from tree_sitter import Node

from utils import text


def judge_no(node: Node) -> bool:
    if node.parent and node.parent.type == 'parenthesized_expression' and len(node.parent.children) == 3:
        if node.parent.parent and node.parent.parent.type == 'not_operator':
            return True
    return False


def get_parent_first(node: Node) -> bool:
    if node.parent and node.parent.type == 'boolean_operator' and len(node.parent.children) == 3 \
            and text(node.parent.children[1]) in ['and', 'or'] and \
            node.parent.parent and node.parent.parent.type == 'parenthesized_expression':
        bool_op = node.parent
        if bool_op.children[0].type == 'comparison_operator' and bool_op.children[2].type == 'comparison_operator':
            op1 = bool_op.children[0]
            op2 = bool_op.children[2]
            if text(op1.children[1]) in [">", "<", ">=", "<="]:
                if text(op2.children[1]) in ['==', '!=']:
                    set1 = {text(op1.children[0]).strip(), text(op1.children[2]).strip()}
                    set2 = {text(op2.children[0]).strip(), text(op2.children[2]).strip()}
                    if set1 == set2:
                        return False
    return True


def compare_hash(str1, str2):
    hash_a = hashlib.sha256(str1.encode('utf-8')).hexdigest()
    hash_b = hashlib.sha256(str2.encode('utf-8')).hexdigest()
    init_a = int(hash_a, 16)
    init_b = int(hash_b, 16)
    return init_a >= init_b


def op_chain(edges: List[Tuple[str, str, str]]) -> Tuple[List[str], str]:
    # 输入小于号左右两边的变量构成的边的集合，输出最长的链
    G = nx.DiGraph()
    for edge in edges:
        G.add_edge(edge[0], edge[1], label=edge[2])
    starts = [x for x in G.nodes() if G.in_degree(x) == 0]
    ends = [x for x in G.nodes() if G.out_degree(x) == 0]
    paths = []
    for start in starts:
        for path in nx.all_simple_paths(G, start, ends):
            paths.append(path)
    paths = sorted(paths, key=lambda x: len(x), reverse=True)
    path = paths[0]
    str = ''
    for i in range(len(path) - 1):
        op = G.get_edge_data(path[i], path[i + 1])['label']
        str += f'{path[i]} {op} '
    str += path[-1]
    return path, str


'''==========================匹配========================'''


def rec_AugmentedAssignment(node: Node) -> bool:
    # a ?= b
    if node.type == 'augmented_assignment':
        return True


def rec_Assignment(node: Node) -> bool:
    # a = a ? b
    if node.type == 'assignment':
        left_id = text(node.child_by_field_name('left'))
        right = node.child_by_field_name('right')
        if right and right.type == 'binary_operator' and text(right.child_by_field_name('left')) == left_id:
            return True


def rec_Equal(node: Node) -> bool:  #OK
    if node.type == 'comparison_operator' and node.children[1].text != b'in' \
            and text(node.children[1]) in ['==', '!=']:
        if not get_parent_first(node):
            return False
        if judge_no(node):
            return False
        else:
            return True


def rec_Equal_nolimit(node: Node) -> bool:  #OK
    if node.type == 'comparison_operator' and node.children[1].text != b'in' \
            and text(node.children[1]) in ['==', '!=']:
        if not get_parent_first(node):
            return False
        else:
            return True


def rec_CmpOptBigger(node: Node) -> bool:
    if node.type == 'comparison_operator' and node.children[1].text != b'in' \
            and text(node.children[1]) in ['>', '>=', '<', '<=']:
        return True


def rec_CmpOptSmaller(node: Node) -> bool:
    if node.type == 'comparison_operator' and node.children[1].text != b'in' \
            and text(node.children[1]) in ['>', '>=', '<', '<=']:
        return True


def rec_Cmp(node: Node) -> bool:  # tx
    if node.type == 'comparison_operator' and node.children[1].text != b'in' \
            and text(node.children[1]) in ['>', '>=', '<', '<=']:
        if get_parent_first(node):
            return True


def rec_exp_cmp(node: Node) -> bool:
    if node.type == 'parenthesized_expression' and len(node.children) == 3:
        if node.children[1].type == 'boolean_operator' and len(node.children[1].children) == 3 \
                and text(node.children[1].children[1]) in ['and', 'or']:
            bool_op = node.children[1]
            if bool_op.children[0].type == 'comparison_operator' and bool_op.children[2].type == 'comparison_operator':
                op_1 = bool_op.children[0]
                op_2 = bool_op.children[2]
                if len(op_1.children) == 3 and len(op_2.children) == 3 \
                        and text(op_1.children[1]) in ['>', '>=', '<', '<='] \
                        and text(op_2.children[1]) in ['==', '!=']:
                    set1 = {text(op_1.children[0]).strip(), text(op_1.children[2]).strip()}
                    set2 = {text(op_2.children[0]).strip(), text(op_2.children[2]).strip()}
                    if set1 == set2:
                        return True


def rec_not_equal_reverse(node: Node) -> bool:
    if node.type == 'not_operator' and len(node.children) == 2 and text(node.children[0]) == 'not':
        if node.children[1].type == 'parenthesized_expression' and len(node.children[1].children) == 3:
            if node.children[1].children[1].type == 'comparison_operator' and len(
                    node.children[1].children[1].children) == 3:
                if text(node.children[1].children[1].children[1]) == '==':
                    return True


def rec_equal_reverse(node: Node) -> bool:
    if node.type == 'not_operator' and len(node.children) == 2 and text(node.children[0]) == 'not':
        if node.children[1].type == 'parenthesized_expression' and len(node.children[1].children) == 3:
            if node.children[1].children[1].type == 'comparison_operator' and len(
                    node.children[1].children[1].children) == 3:
                if text(node.children[1].children[1].children[1]) == '!=':
                    return True

def match_Equal(node: Node) -> bool:
    # a == b
    pass


def match_LeftConst(node: Node) -> bool:
    # const op a
    pass


'''==========================替换========================'''


def cvt_EqualBiggerHashTrans(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # Bigger Hash == Smaller Hash
    # Smaller Hash == Bigger Hash
    # rec_Equal
    if len(node.children) == 3:
        if judge_no(node) and text(node.children[1]) == '!=':
            [a, op, b] = [text(x) for x in node.children]
            if compare_hash(a, b):
                return [(node.end_byte, node.start_byte),
                        (node.start_byte, f'{b} {op} {a}')]
        if (not judge_no(node)) and text(node.children[1]) == '==':
            [a, op, b] = [text(x) for x in node.children]
            if compare_hash(a, b):
                return [(node.end_byte, node.start_byte),
                        (node.start_byte, f'{b} {op} {a}')]


def cvt_EqualSmallHashTrans(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # Bigger Hash == Smaller Hash
    # Smaller Hash == Bigger Hash
    # rec_Equal
    if len(node.children) == 3:
        if judge_no(node) and text(node.children[1]) == '!=':
            [a, op, b] = [text(x) for x in node.children]
            if not compare_hash(a, b):
                return [(node.end_byte, node.start_byte),
                        (node.start_byte, f'{b} {op} {a}')]
        if not judge_no(node) and text(node.children[1]) == '==':
            [a, op, b] = [text(x) for x in node.children]
            if not compare_hash(a, b):
                return [(node.end_byte, node.start_byte),
                        (node.start_byte, f'{b} {op} {a}')]


def cvt_NotEqualBiggerHashTrans(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # Bigger Hash == Smaller Hash
    # Smaller Hash == Bigger Hash
    # rec_Equal
    if len(node.children) == 3:
        if judge_no(node) and text(node.children[1]) == '==':
            [a, op, b] = [text(x) for x in node.children]
            if compare_hash(a, b):
                return [(node.end_byte, node.start_byte),
                        (node.start_byte, f'{b} {op} {a}')]
        if not judge_no(node) and text(node.children[1]) == '!=':
            [a, op, b] = [text(x) for x in node.children]
            if compare_hash(a, b):
                return [(node.end_byte, node.start_byte),
                        (node.start_byte, f'{b} {op} {a}')]


def cvt_NotEqualSmallHashTrans(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # Bigger Hash == Smaller Hash
    # Smaller Hash == Bigger Hash
    # rec_Equal
    if len(node.children) == 3:
        if judge_no(node) and text(node.children[1]) == '==':
            [a, op, b] = [text(x) for x in node.children]
            if not compare_hash(a, b):
                return [(node.end_byte, node.start_byte),
                        (node.start_byte, f'{b} {op} {a}')]
        if not judge_no(node) and text(node.children[1]) == '!=':
            [a, op, b] = [text(x) for x in node.children]
            if not compare_hash(a, b):
                return [(node.end_byte, node.start_byte),
                        (node.start_byte, f'{b} {op} {a}')]


def cvt_AugmentedAssignment2Assignment(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # a ?= b -> a = a ? b
    if rec_AugmentedAssignment(node):
        if len(node.children) == 3:
            [a, op, b] = [text(x) for x in node.children]
            new_str = f'{a} = {a} {op[:-1]} {b}'
            return [(node.end_byte, -len(text(node))),
                    (node.start_byte, new_str)]


def cvt_Assignment2AugmentedAssignment(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # a = a ? b -> a ?= b
    a = text(node.child_by_field_name('left'))
    op = text(node.children[2].children[1])
    if len(node.children[2].children) < 3:
        return
    b = text(node.children[2].children[2])
    new_str = f'{a} {op}= {b}'
    return [(node.end_byte, node.start_byte),
            (node.start_byte, new_str)]


def cvt_Equal2NotEqual(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # a == b -> ! (a != b)
    if len(node.children) == 3:
        [a, op, b] = [text(x) for x in node.children]
        reverse_op_dict = {'==': '!='}
        if reverse_op_dict[op]:
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f'not ({a} {reverse_op_dict[op]} {b})')]
        else:
            return []


def cvt_NotEqual2Equal(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # a != b -> ! (a == b)
    if len(node.children) == 3:
        [a, op, b] = [text(x) for x in node.children]
        reverse_op_dict = {'!=': '=='}
        if reverse_op_dict[op]:
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f'not ({a} {reverse_op_dict[op]} {b})')]
        else:
            return []


def cvt_Bigger2Smaller(node: Node) -> List[Tuple[int, Union[int, str]]]:
    if len(node.children) == 3:
        [a, op, b] = [text(x) for x in node.children]
        reverse_op_dict = {'<': '>', '<=': '>='}
        if op in ['<=', '<']:
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f'{b} {reverse_op_dict[op]} {a}')]


def cvt_Smaller2Bigger(node: Node) -> List[Tuple[int, Union[int, str]]]:
    if len(node.children) == 3:
        [a, op, b] = [text(x) for x in node.children]
        reverse_op_dict = {'>': '<', '>=': '<='}
        if op in ['>', '>=']:
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f'{b} {reverse_op_dict[op]} {a}')]


def cvt_Equal(node: Node) -> List[Tuple[int, Union[int, str]]]:  # tx
    if len(node.children) == 3:
        [a, op, b] = [text(x) for x in node.children]
        if op in ['<=']:
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f'({a} < {b} or {a} == {b})')]
        if op in ['<']:
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f'({a} <= {b} and {a} != {b})')]
        if op in ['>=']:
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f'({a} > {b} or {a} == {b})')]
        if op in ['>']:
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f'({a} >= {b} and {a} != {b})')]


def cvt_cmp(node: Node) -> List[Tuple[int, Union[int, str]]]:
    ret = []
    bool_op = node.children[1]
    ret.append((node.end_byte, node.start_byte))
    op1 = bool_op.children[0]
    [a, op, b] = [text(x) for x in op1.children]
    if op in ['>', '<']:
        dict_op = {'>': '>=', '<': '<='}
        ret.append((node.start_byte, f'{a} {dict_op[op]} {b}'))
    elif op in ['>=', '<=']:
        dict_op = {'>=': '>', '<=': '<'}
        ret.append((node.start_byte, f'{a} {dict_op[op]} {b}'))
    return ret


def cvt_NotEqual2Equal_reverse(node: Node) -> List[Tuple[int, Union[int, str]]]:
    ret = [(node.end_byte, node.start_byte)]
    bool_op = node.children[1].children[1]
    [a, op, b] = [text(x) for x in bool_op.children]
    dict_op = {'==': '!='}
    ret.append((node.start_byte, f'{a} {dict_op[op]} {b}'))
    return ret


def cvt_Equal2NotEqual_reverse(node: Node) -> List[Tuple[int, Union[int, str]]]:
    ret = [(node.end_byte, node.start_byte)]
    bool_op = node.children[1].children[1]
    [a, op, b] = [text(x) for x in bool_op.children]
    dict_op = {'!=': '=='}
    ret.append((node.start_byte, f'{a} {dict_op[op]} {b}'))
    return ret

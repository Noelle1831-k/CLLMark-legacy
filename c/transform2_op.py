import hashlib
from typing import List, Tuple, Union

from tree_sitter import Node

from utils import text


def judge_no(node: Node) -> bool:
    if node.parent and node.parent.type == 'parenthesized_expression' and len(node.parent.children) == 3:
        if node.parent.parent and node.parent.parent.type == 'unary_expression' and text(
                node.parent.parent.children[0]) == "!":
            return True
    return False


def get_parent_first(node: Node) -> bool:
    if node.parent and node.parent.type == 'binary_expression' and len(node.parent.children) == 3 \
            and text(node.parent.children[1]) in ['&&', '||'] and \
            node.parent.parent and node.parent.parent.type == 'parenthesized_expression':
        bool_op = node.parent
        if bool_op.children[0].type == 'binary_expression' and bool_op.children[2].type == 'binary_expression':
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


def compare_hash_sha224(str1, str2):
    hash_a = hashlib.sha224(str1.encode('utf-8')).hexdigest()
    hash_b = hashlib.sha224(str2.encode('utf-8')).hexdigest()
    init_a = int(hash_a, 16)
    init_b = int(hash_b, 16)
    return init_a >= init_b


'''==========================匹配========================'''


def rec_AugmentedAssignment(node: Node) -> bool:
    # a ?= b
    if node.type == 'assignment_expression':
        if node.child_count >= 2 and text(node.children[1]) in ['+=', '-=', '*=', '/=', '%=', '<<=', '>>=']:
            return True


def rec_Assignment(node: Node) -> bool:
    # a = a ? b
    if node.type == 'assignment_expression' and len(node.children) == 3 and text(node.children[1]) == '=':
        left = text(node.children[0])
        if node.children[2].type == 'binary_expression' and len(node.children[2].children) == 3 and text(
                node.children[2].children[1]) in ['+', '-', "*", "/", '%', '<<', '>>']:
            op = node.children[2]
            left_same = text(op.children[0])
            return left.strip() == left_same.strip()


def rec_Equal(node: Node) -> bool:
    if node.type == 'binary_expression' and node.children[1].text != b'in' \
            and text(node.children[1]) in ['==', '!=']:
        if not get_parent_first(node):
            return False
        if judge_no(node):
            return False
        else:
            return True


def rec_exp_cmp(node: Node) -> bool:
    if node.type == 'parenthesized_expression' and len(node.children) == 3:
        if node.children[1].type == 'binary_expression' and len(node.children[1].children) == 3 \
                and text(node.children[1].children[1]) in ['&&', '||']:
            bool_op = node.children[1]
            if bool_op.children[0].type == 'binary_expression' and bool_op.children[2].type == 'binary_expression':
                op_1 = bool_op.children[0]
                op_2 = bool_op.children[2]
                if len(op_1.children) == 3 and len(op_2.children) == 3 \
                        and text(op_1.children[1]) in ['>', '>=', '<', '<='] \
                        and text(op_2.children[1]) in ['==', '!=']:
                    set1 = {text(op_1.children[0]).strip(), text(op_1.children[2]).strip()}
                    set2 = {text(op_2.children[0]).strip(), text(op_2.children[2]).strip()}
                    if set1 == set2:
                        return True


def rec_Equal_nolimit(node: Node) -> bool:
    if node.type == 'binary_expression' \
            and text(node.children[1]) in ['==', '!=']:
        if not get_parent_first(node):
            return False
        else:
            return True


def rec_CmpOptBigger(node: Node) -> bool:
    # a > b
    if node.type == 'binary_expression' \
            and text(node.children[1]) in ['>', '>=']:
        return True


def rec_CmpOptSmaller(node: Node) -> bool:
    # a <= b
    if node.type == 'binary_expression' \
            and text(node.children[1]) in ['<', '<=']:
        return True


def rec_Cmp(node: Node) -> bool:  # tx
    if node.type == 'binary_expression' \
            and text(node.children[1]) in ['>', '>=', '<', '<=']:
        if not get_parent_first(node):
            return False
        else:
            return True


def rec_not_equal_reverse(node: Node) -> bool:
    if node.type == 'unary_expression' and len(node.children) == 2 and text(node.children[0]) == '!':
        if node.children[1].type == 'parenthesized_expression' and len(node.children[1].children) == 3:
            if node.children[1].children[1].type == 'binary_expression' and len(
                    node.children[1].children[1].children) == 3:
                if text(node.children[1].children[1].children[1]) == '==':
                    return True


def rec_equal_reverse(node: Node) -> bool:
    if node.type == 'unary_expression' and len(node.children) == 2 and text(node.children[0]) == '!':
        if node.children[1].type == 'parenthesized_expression' and len(node.children[1].children) == 3:
            if node.children[1].children[1].type == 'binary_expression' and len(
                    node.children[1].children[1].children) == 3:
                if text(node.children[1].children[1].children[1]) == '!=':
                    return True


def match_Equal(node: Node) -> bool:
    pass


def match_NotEqual(node: Node) -> bool:
    pass


def match_LeftConst(node: Node) -> bool:
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


def cvt_Equal2NotEqual(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # a == b -> ! (a != b)
    if len(node.children) == 3:
        [a, op, b] = [text(x) for x in node.children]
        reverse_op_dict = {'==': '!='}
        if reverse_op_dict[op]:
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f'! ({a} {reverse_op_dict[op]} {b})')]
        else:
            return []


def cvt_NotEqual2Equal(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # a != b -> ! (a == b)
    if len(node.children) == 3:
        [a, op, b] = [text(x) for x in node.children]
        reverse_op_dict = {'!=': '=='}
        if reverse_op_dict[op]:
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f'! ({a} {reverse_op_dict[op]} {b})')]
        else:
            return []


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


def cvt_AugmentedAssignment2Assignment(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # a ?= b -> a = a ? b
    if rec_AugmentedAssignment(node):
        if len(node.children) == 3:
            [a, op, b] = [text(x) for x in node.children]
            new_str = f'{a} = {a} {op[:-1]} {b}'
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, new_str)]


def cvt_Assignment2AugmentedAssignment(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # a = a ? b -> a ?= b
    a = text(node.children[0])
    op = text(node.children[2].children[1])
    if len(node.children[2].children) < 3:
        return []
    b = text(node.children[2].children[2])
    new_str = f'{a} {op}= {b}'
    return [(node.end_byte, node.start_byte),
            (node.start_byte, new_str)]


def cvt_Bigger2Smaller(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # a > b -> b < a
    if len(node.children) == 3:
        [a, op, b] = [text(x) for x in node.children]
        reverse_op_dict = {'>': '<', '>=': '<='}
        return [(node.end_byte, node.start_byte),
                (node.start_byte, f'{b} {reverse_op_dict[op]} {a}')]


def cvt_Smaller2Bigger(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # a <= b -> b >= a
    if len(node.children) == 3:
        [a, op, b] = [text(x) for x in node.children]
        reverse_op_dict = {'<': '>', '<=': '>='}
        return [(node.end_byte, node.start_byte),
                (node.start_byte, f'{b} {reverse_op_dict[op]} {a}')]


def cvt_Equal(node: Node) -> List[Tuple[int, Union[int, str]]]:  # tx
    [a, op, b] = [text(x) for x in node.children]
    if op in ['<=']:
        # a < b || a == b
        return [(node.end_byte, node.start_byte),
                (node.start_byte, f'({a} < {b} || {a} == {b})')]
    if op in ['<']:
        # !(b < a || a == b)
        return [(node.end_byte, node.start_byte),
                (node.start_byte, f'({a} <= {b} && {a} != {b})')]
    if op in ['>=']:
        # a > b || a == b
        return [(node.end_byte, node.start_byte),
                (node.start_byte, f'({a} > {b} || {a} == {b})')]
    if op in ['>']:
        # !(b > a || a == b)
        return [(node.end_byte, node.start_byte),
                (node.start_byte, f'({a} >= {b} && {a} != {b})')]


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



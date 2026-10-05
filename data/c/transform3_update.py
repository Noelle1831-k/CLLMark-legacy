from typing import List, Tuple, Union

from tree_sitter import Node

from utils import text

'''==========================匹配========================'''


def rec_LeftUpdate(node: Node) -> bool:
    # ++i or --i
    if node.type in ['update_expression']:
        if node.parent.type not in ['subscript_expression', 'subscript_argument_list', 'assignment_expression',
                                    'argument_list', 'binary_expression']:
            # 不是a[++i] 不是*p(++i)不是a=++i
            if node.children[1].type == 'identifier':
                return True


def rec_RightUpdate(node: Node) -> bool:
    # i++ or i--
    if node.type in ['update_expression']:
        if node.parent.type not in ['subscript_expression', 'subscript_argument_list', 'assignment_expression',
                                    'argument_list', 'binary_expression']:
            # 不是a[i++] 不是*p(i++)不是a=i++
            if node.children[0].type == 'identifier':
                return True

    pass


def rec_ToLeft(node: Node) -> bool:
    return rec_RightUpdate(node)


def rec_ToRight(node: Node) -> bool:
    return rec_LeftUpdate(node)


'''==========================替换========================'''


def cvt_ToRight(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # i++
    temp_node = node.children[0]
    return [(temp_node.end_byte, temp_node.start_byte),
            (node.end_byte, text(temp_node))]


def cvt_ToLeft(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # ++i
    temp_node = node.children[1]
    return [(temp_node.end_byte, temp_node.start_byte),
            (node.start_byte, text(temp_node))]

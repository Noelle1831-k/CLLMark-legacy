from typing import List, Tuple, Union

from tree_sitter import Node

from dataset.MBPP_G.MBPP_195 import first
from dataset.MBPP_G.MBPP_788 import new_tuple
from utils import text

'''==========================匹配========================'''
def rec_string(node: Node) -> bool:
    if node.type == 'string':
        return True

def rec_not_format_string_with_f(node: Node) -> bool:
    if node.type == "string":
        for n in node.children:
            if n.type == 'interpolation':
                return False
        string_start_text = text(node.children[0])
        if 'b' in string_start_text:
            return False
        if 'r' in string_start_text:
            return False
        if 'f' in string_start_text:
            return True

def rec_not_format_string_without_f(node: Node) -> bool:
    if node.type == "string":
        for n in node.children:
            if n.type == 'interpolation':
                return False
        string_start_text = text(node.children[0])
        if 'b' in string_start_text:
            return False
        if 'r' in string_start_text:
            return False
        if 'f' not in string_start_text:
            return True

def match_StringSingle(node: Node) -> bool:
    if node.type == 'string':
        if '"""' in str or "'''" in str:
            return False
        if text(node)[0] == "'" and text(node)[-1] == "'":
            return True

def match_StringDouble(node: Node) -> bool:
    if node.type == 'string':
        if '"""' in str or "'''" in str:
            return False
        if text(node)[0] == '"' and text(node)[-1] == '"':
            return True

def match_format_string(node: Node) -> bool:
    if node.type == 'string':
        if text(node)[0] == 'f' and len(node.parent.children) > 2:
            return True

'''==========================替换========================'''
def cvt_single_quotation(node: Node) -> List[Tuple[int, Union[int, str]]]:
    str = text(node)
    if '"""' in str or "'''" in str:
        return
    str = str.replace("'", '"').replace('"', '"')
    # 找到第一个和最后一个引号的位置
    first_quote = str.find('"')
    last_quote = str.rfind('"')

    # 如果有引号，则将第一个和最后一个引号替换为双引号
    new_str = str[:first_quote] + "'" + str[first_quote + 1:last_quote] + "'" + str[last_quote + 1:]

    return [(node.end_byte, node.start_byte), (node.start_byte, new_str)]

def cvt_double_quotation(node: Node) -> List[Tuple[int, Union[int, str]]]:
    # ''
    str = text(node)
    if '"""' in str or "'''" in str:
        return
    str = str.replace('"', "'").replace("'", "'")
    # 找到第一个和最后一个引号的位置
    first_quote = str.find("'")
    last_quote = str.rfind("'")

    # 如果有引号，则将第一个和最后一个引号替换为双引号
    new_str = str[:first_quote] + '"' + str[first_quote + 1:last_quote] + '"' + str[last_quote + 1:]

    return [(node.end_byte, node.start_byte), (node.start_byte, new_str)]

def cvt_add_f(node: Node) -> List[Tuple[int,Union[int,str]]]:
    # f'' with no interpolation -> ''
    str = text(node)
    if '"""' in str or "'''" in str:
        return
    str_start = node.children[0]
    new_start = 'f' + text(str_start)
    return [(str_start.end_byte,str_start.start_byte),(str_start.start_byte,new_start)]


def cvt_del_f(node: Node) -> List[Tuple[int,Union[int,str]]]:
    # f'' with no interpolation -> ''
    str = text(node)
    if '"""' in str or "'''" in str:
        return
    str_start = node.children[0]
    new_start = text(str_start).replace("f","")
    return [(str_start.end_byte,str_start.start_byte),(str_start.start_byte,new_start)]
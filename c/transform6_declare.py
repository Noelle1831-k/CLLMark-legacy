from typing import List, Tuple, Union, Dict, Set

from tree_sitter import Node

from utils import text

neglect_list = [',', ';', 'subscript_expression', 'call_expression', 'primitive_type', 'sized_type_specifier',
                'struct_specifier', 'storage_class_specifier']


def get_declare_info(node: Node) -> Tuple[Dict[str, List[str]], Dict[str, List[Node]]]:
    # 返回node代码块中所有类型的变量名以及节点字典
    type_ids_dict, type_dec_node = {}, {}
    for child in node.children:
        if child.type == 'declaration':
            type = text(child.child_by_field_name('type'))
            if child.children[0].type == 'storage_class_specifier':
                type = 'static ' + type
            if child.children[0].type == 'type_qualifier':
                type = 'const ' + type
            type_ids_dict.setdefault(type, [])
            type_dec_node.setdefault(type, [])
            type_dec_node[type].append(child)
            for each in child.children[1: -1]:
                if each.type in neglect_list:  # 不考虑类型名、结构体、const、static等
                    continue
                type_ids_dict[type].append(text(each))
    return type_ids_dict, type_dec_node


def contain_id(node: Node, contain: Set) -> None:
    # 返回node节点子树中的所有变量名
    if node.child_by_field_name('index'):  # a[i] < 2中的index：i
        contain.add(text(node.child_by_field_name('index')))
    if node.type == 'identifier' and node.parent.type not in ['subscript_expression', 'call_expression']:  # a < 2中的a
        contain.add(text(node))
    if not node.children:
        return
    for n in node.children:
        contain_id(n, contain)


def get_indent(start_byte: int, code: str) -> int:
    indent = 0
    i = start_byte
    while i >= 0 and code[i] != '\n':
        if code[i] == ' ':
            indent += 1
        elif code[i] == '\t':
            indent += 4
        i -= 1
    return indent


def get_type(node: Node) -> str:
    type = ''
    for child in node.children:
        if child.type == 'storage_class_specifier':
            type += 'static '
        if child.type == 'type_qualifier':
            type += 'const '
    type += text(node.child_by_field_name('type'))
    return type


'''==========================匹配========================'''


def rec_DeclareMerge(node: Node) -> bool:
    # int a, b=0;
    if node.type == 'declaration' and node.children[0].type not in ['storage_class_specifier',
                                                         'type_qualifier']:  # not static const
        if node.parent.type != 'for_statement':
            ids = set()
            contain_id(node, ids)
            return len(ids) > 1


def rec_DeclareSplit(node: Node) -> bool:
    # int a; \n int b=0;
    type_list = []
    for child in node.children:
        if child.type == 'declaration':
            type = get_type(child)
            if type in type_list:
                return True
            type_list.append(type)




'''==========================替换========================'''


def cvt_DeclareMerge2Split(node: Node, code: str) -> List[Tuple[int, Union[int, str]]]:
    # int a, b; -> int a; int b;
    type = get_type(node)
    ret = []
    indent = get_indent(node.start_byte, code)
    ret.append((node.end_byte, node.start_byte))

    j = 0
    for i, child in enumerate(node.children[1: -1]):
        if child.type == ',':
            continue
        indentifer = text(child)
        # 检查是否是最后一个需要处理的 child
        if j == sum(1 for c in node.children[1:-1] if c.type != ',') - 1:
            # 如果是最后一个，不添加 \n
            ret.append((node.start_byte - indent, f"{indent * ' '}{type} {text(child)};\n"))
        else:
            # 如果不是最后一个，添加 \n
            ret.append((node.start_byte - indent, f"{indent * ' '}{type} {text(child)};\n"))
        j += 1
    if j > 1:
        return ret


def cvt_DeclareSplit2Merge(node: Node, code: str) -> List[Tuple[int, Union[int, str]]]:
    # int a; int b; -> int a, b;
    ret = []
    type_ids_dict, type_dec_node = get_declare_info(node)
    # input(type_ids_dict)
    for type, ids in type_ids_dict.items():
        indent = 0
        if len(ids) > 1:
            start_byte = type_dec_node[type][0].start_byte
            for node in type_dec_node[type]:
                indent = get_indent(node.start_byte,code)
                ret.append((node.end_byte, node.start_byte - indent))
            str = f"{indent * ' '}{type} {', '.join(type_ids_dict[type])};"
            ret.append((start_byte - indent, str))
    return ret

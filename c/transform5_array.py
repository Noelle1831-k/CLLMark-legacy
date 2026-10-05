import re
from typing import List, Tuple, Union

from tree_sitter import Node

from utils import text

def remove_sizeof(list):
    str1 = ''
    i = 0
    for x in list:
        if 'sizeof' in list[i] and i != len(list) - 1:
            list[i] = ''
            list[i + 1] = ''
        elif 'sizeof' in list[i] and i == len(list) - 1:
            list[-1] = ''
            list[-2] = ''
        i += 1
    for x in list:
        str1 += x
    str1 = remove_outer_parentheses(str1.strip())
    return str1
def remove_outer_parentheses(s):

    while True:
        if not s or s[0] != '(' or s[-1] != ')':
            break  # 字符串为空或不以括号包围，结束循环

        stack = 0
        is_outer = True
        for i in range(len(s)):
            if s[i] == '(':
                stack += 1
            elif s[i] == ')':
                stack -= 1
                if stack == 0 and i != len(s) - 1:
                    is_outer = False
                    break
            # 其他字符忽略

        if is_outer:
            s = s[1:-1]  # 移除最外层括号
        else:
            break  # 最外层括号不是多余的，结束循环

    return s


def is_trans_nest_array(node):
    text_node = text(node)
    pattern = r"\*\([^\+]+\+[^\)]+\)"
    is_match = bool(re.search(pattern,text_node))
    return is_match

def get_mem_array(node):
    if node.type == 'init_declarator' and len(node.children) == 3 \
            and node.children[0].type == 'pointer_declarator' and not node.children[0].children[
                                                                       1].type == 'pointer_declarator' and text(
        node.children[1]).strip() == '=' \
            and node.children[2].type == 'cast_expression':
        cast_call = node.children[2]
        if cast_call.children[-1] and cast_call.children[-1].type == 'call_expression' and \
                cast_call.children[-1].children[0]:
            if text(cast_call.children[-1].children[0]) == 'malloc':
                return True

def get_indent(start_byte: int, code: str) -> int:
    indent = 0
    i = start_byte
    while i >= 0 and code[i] != '\n':
        if code[i] == ' ':
            indent += 1
        elif code[i] == '\t':
            indent += 8
        i -= 1
    return indent
    
def get_array_dim(node: Node) -> int:
    # a[i], a[i][j]
    dim = 0
    temp_node = node
    while temp_node.child_count:
        if type(temp_node) == 'subscript_expression':
            return 10
        temp_node = temp_node.children[0]
        dim += 1
    return dim

def get_pointer_dim(node: Node) -> int:
    # *(a + 0), *(*(a + m) + n), *(*(*(a + m) + n) + l)
    pointer = []
    def traverse(node, pointer):
        if node.type == 'pointer_expression':
            pointer.append(node)
        for child in node.children:
            traverse(child, pointer)
    traverse(node, pointer)
    return len(pointer)

def get_size(param_node: Node) -> str:
    if param_node.type == 'sizeof_expression':   # sizeof(type) * n 或 sizeof(type) * (n + m)
        expression = param_node.child_by_field_name('value') # (type) * n
        value = expression.child_by_field_name('value') # * n
        if value:
            size = value.child_by_field_name('argument') # n
        else:
            size = expression.child_by_field_name('left') # (unknown) * (n + m)
    elif param_node.type == 'binary_expression':   # s * sizeof(type)
        size = param_node.child_by_field_name('left')   # s
    elif param_node.type == 'number_literal':   # n
        size = param_node
    return text(size)


def split_string(s):
    result = []      # 最终结果列表
    buffer = []      # 当前缓冲区
    stack = []       # 用于跟踪括号的栈

    for index, char in enumerate(s):
        if char == '(':
            stack.append('(')
            buffer.append(char)
        elif char == ')':
            if stack:
                stack.pop()
            else:
                print(f"警告: 在位置 {index} 遇到未匹配的右括号 ')'.")
            buffer.append(char)
        elif char == '*' and not stack:
            # 当前字符是星号且不在括号内
            if buffer:
                segment = ''.join(buffer)
                result.append(segment)
                buffer = []
            result.append('*')
        else:
            buffer.append(char)

    # 添加剩余的部分
    if buffer:
        result.append(''.join(buffer))

    return result


def is_nest_array(node: Node) -> bool:
    # a[b[i]]
    stack = []
    for c in text(node):
        if c == '[':
            if stack:
                return True
            stack.append(c)
        elif c == ']':
            stack.pop()
    return False

def get_left_id(node: Node) -> Union[Node, None]:
    while node:
        if node.type == 'binary_expression':
            node = node.child_by_field_name('left')
        elif node.type == 'identifier':
            return node
        else:
            return

'''==========================匹配========================'''
def rec_StaticMem(node: Node) -> bool:
    # type a[n],最多两维就够了
    min_dim = 3
    if node.type == 'declaration':
        for child in node.children:
            if child.type == 'array_declarator':
                list1 = []
                dim = get_array_dim(child)
                if min_dim > dim:
                    min_dim = dim
    if min_dim <= 2:
        return True


def rec_DynMemOneLine(node: Node) -> bool:
    # type *a = (type *)malloc(sizeof(type) * n)
    if node.type == 'declaration':
        for n in node.children:
            if get_mem_array(n):
                return True

                    
def rec_DynMemTwoLine(node: Node) -> bool:
    pass

def rec_DynMem(node: Node) -> bool:
    return rec_DynMemOneLine(node)

def rec_Array(node: Node) -> bool:
    # a[n] or a[m][n] or a[m][n][l]
    if node.type == 'subscript_expression' \
            and node.parent.type not in ['subscript_expression', 'pointer_expression', 'comma_expression'] \
            and node.children[0].type not in ['call_expression', 'field_expression', 'parenthesized_expression']:     # char *(a)[n] a[b[i]] &a[n] x.a[i]不处理
        if not is_nest_array(node): # 忽略嵌套的数组，例如a[b[i]]
            if not is_trans_nest_array(node):
                dim = get_array_dim(node)
                return dim < 4

def rec_Pointer(node: Node) -> bool:
    # *(*a + 0) or *(*(a + m) + n);
    if node.type == 'pointer_expression' and '&' not in text(node) and node.children[1] and node.children[1].type == 'parenthesized_expression' and node.children[1].children[1].type == 'binary_expression':
        dim = get_pointer_dim(node)
        while node.parent:
            if node.parent.type == 'pointer_expression':
                return False
            node = node.parent
        return dim < 4

'''==========================替换========================'''
def cvt_Static2Dyn(node: Node, code: str) -> List[Tuple[int, Union[int, str]]]:
    # type a[n] -> type *a = (type *)malloc(sizeof(type) * n)
    type = text(node.child_by_field_name('type'))
    indent = get_indent(node.start_byte, code)
    ret = []
    for i, child in enumerate(node.children):
        if child.type == 'struct_specifier':
            body = child.child_by_field_name('body')
            if body:    # 如果存在struct A {} a[10];这种情况，不处理
                ret.append()
    for child in node.children:
        if child.type == 'array_declarator':
            if child.children[0].type != 'identifier':
                ret.append()
            dim = get_array_dim(child)
            if dim == 1:
                id = text(child.children[0])
                size = text(child.children[2])
                ret.append((child.end_byte, child.start_byte))
                if child.children[2].child_count > 1:
                    ret.append((child.start_byte,f"*{id} = ({type}*)malloc(sizeof({type}) * ({size}))"))
                else:
                    ret.append((child.start_byte, f"*{id} = ({type}*)malloc(sizeof({type}) * {size})"))
            else:
                    ret.append(())
    return ret
        
def cvt_Dyn2Static(node: Node) -> List[Tuple[int, Union[int, str]]]:
        ret = []
        for n in node.children:
            if get_mem_array(n) and n.type == 'init_declarator':
                pointer_node = n.children[0].children[0]
                del_node_start = n.children[0].children[1].end_byte
                del_node_end = n.end_byte
                call_expression = n.children[2].children[-1]
                if call_expression.children[-1] and call_expression.children[-1].type == 'argument_list':
                    argument_list = call_expression.children[-1]
                    if argument_list.children[1].type == 'sizeof_expression':
                        ret.append()
                    elif len(argument_list.children) == 3 :
                        op = argument_list.children[1]
                        list_op = split_string(text(op))
                        str_op = remove_sizeof(list_op)
                        ret.append((pointer_node.end_byte, pointer_node.start_byte))
                        ret.append((del_node_start,f'[{str_op}]'))
                        ret.append((del_node_end, del_node_start))
        return ret




def cvt_Array2Pointer(node: Node) -> List[Tuple[int, Union[int, str]]]:

    dim = get_array_dim(node)
    if dim == 1:
        # a[i] -> *(a + i)
        id = text(node.children[0])
        index = text(node.child_by_field_name('index'))
        return [(node.end_byte, node.start_byte),
                (node.start_byte, f"*({id} + {index})")]
    elif dim == 2:
        # a[i][j] -> *(*(a + i) + j);
        id = text(node.children[0].children[0])
        try:
            index_1 = text(node.children[0].children[2])
            index_2 = text(node.children[2])
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f"*(*({id} + {index_1}) + {index_2})")]
        except:
            return
    elif dim == 3:
        # a[i][j][k] -> *(*(*(a + i) + j) + k)
        id = text(node.children[0].children[0].children[0])
        try:
            index_1 = text(node.children[0].children[0].children[2])
            index_2 = text(node.children[0].children[2])
            index_3 = text(node.children[2])
            return [(node.end_byte, node.start_byte),
                    (node.start_byte, f"*(*(*({id} + {index_1}) + {index_2}) + {index_3})")]
        except:
            return

def cvt_Pointer2Array(node: Node, code: str) -> List[Tuple[int, Union[int, str]]]:
    ret = []
    dim = get_pointer_dim(node)
    try:
        if dim == 1:
            # *(a + i) -> a[i]
            argument = node.child_by_field_name('argument')
            if argument.child_count == 0:   # *p
                id = argument
                index = 0
            else:
                binary_expression = argument.children[1]
                id = get_left_id(binary_expression)
                if not id or not id.next_sibling:
                    ret.append([])
                index = code[id.next_sibling.end_byte:binary_expression.end_byte]
            ret.append((node.end_byte, node.start_byte - node.end_byte))
            ret.append((node.start_byte, f"{text(id)}[{index.strip()}]"))
        elif dim == 2:
            # *(*a + 0) -> a[i][j]
            binary_expression = node.child_by_field_name('argument').children[1]
            left = binary_expression.child_by_field_name('left')
            right = binary_expression.child_by_field_name('right')
            if not left or not right:
                ret.append([])
            if left.type == 'pointer_expression':
                binary_expression = left.child_by_field_name('argument').children[1]
                if right and right.type in ['number_literal', 'identifier']:
                    index_2 = text(right) 
                else:   # *(*(a + i))
                    index_2 = 0
            elif right.type == 'pointer_expression' and left.type in ['number_literal', 'identifier']:
                binary_expression = right.child_by_field_name('argument').children[1]
                index_2 = text(left)
            else:
                ret.append()
            id = get_left_id(binary_expression)
            index_1 = code[id.next_sibling.end_byte:binary_expression.end_byte]
            ret.append((node.end_byte, node.start_byte - node.end_byte))
            ret.append((node.start_byte, f"{text(id)}[{index_1.strip()}][{index_2.strip()}]"))
        elif dim == 3:
            # *(*(*(a + m) + n) + l) -> a[i][j][k]
            binary_expression = node.child_by_field_name('argument').children[1]
            left = binary_expression.child_by_field_name('left')
            right = binary_expression.child_by_field_name('right')
            if not left or not right:
                ret.append([])
            if left.type == 'pointer_expression':
                binary_expression = left.child_by_field_name('argument').children[1]
                if right and right.type in ['number_literal', 'identifier']:
                    index_3 = text(right) 
                else:
                    index_3 = 0
            elif right.type == 'pointer_expression' and left.type in ['number_literal', 'identifier']:
                binary_expression = right.child_by_field_name('argument').children[1]
                index_3 = text(left)
            else:
                ret.append([])
            left = binary_expression.child_by_field_name('left')
            right = binary_expression.child_by_field_name('right')
            if not left or not right:
                ret.append([])
            if left.type == 'pointer_expression':
                binary_expression = left.child_by_field_name('argument').children[1]
                if right and right.type in ['number_literal', 'identifier']:
                    index_2 = text(right) 
                else:
                    index_2 = 0
            elif right.type == 'pointer_expression' and left.type in ['number_literal', 'identifier']:
                binary_expression = right.child_by_field_name('argument').children[1]
                index_2 = text(left)
            else:
                ret.append()
            index_1 = text(binary_expression.child_by_field_name('right'))
            id = text(binary_expression.child_by_field_name('left'))
            ret.append((node.end_byte, node.start_byte - node.end_byte))
            ret.append((node.start_byte, f"{id}[{index_1.strip()}][{index_2.strip()}][{index_3.strip()}]"))
        return ret
    except:
        return
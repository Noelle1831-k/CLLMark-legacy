from tree_sitter import Node

from utils import text


def rec_func(node: Node) -> bool:
    # return a, b, ...
    if node.type == 'function_definition':
        for n in node.children:
            if n.type == 'block':
                if text(n).replace(' ','') != '':
                    for n_ in n.children:
                        if n_.type == 'function_definition':
                            return False
                else:
                    return False
        return True
def cvt_func(node:Node):
    func_block = text(node)
    func_name = text(node.children[1])
    return func_name,func_block

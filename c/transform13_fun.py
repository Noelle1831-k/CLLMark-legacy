from tree_sitter import Node

from utils import text


def rec_func(node: Node) -> bool:
    # return a, b, ...
    if node.type == 'function_definition':
        if 'compound_statement' not in [x.type for x in node.children]:
            return False
        for n in node.children:
            if n.type == 'compound_statement':
                if not text(n).replace(" ",'') == "{}":
                    for n_ in n.children:
                        if n_.type == 'function_definition':
                            return False
                else:
                    return False
        return True

def cvt_func(node:Node):
    if not node.children[1].type == "function_declarator":
        func_name = text(node.children[-2].children[1].children[0])
    else:
        func_name = text(node.children[1].children[0])
    func_block = text(node)
    if "::" in func_name:
        func_name = func_name.split("::",1)[-1]
    return func_name,func_block
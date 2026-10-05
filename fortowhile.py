import argparse
import ast
import os
import astor

class ForToWhileTransformer(ast.NodeTransformer):
    def __init__(self):
        self.modified = False  # 标志是否进行了转换

    def visit_For(self, node):
        """
        转换for循环为while循环。
        """
        # 首先访问子节点
        self.generic_visit(node)

        # 创建一个新的变量来保存迭代器
        iter_var = ast.Name(id=f'_iter_{node.lineno}_{node.col_offset}', ctx=ast.Store())
        iter_assign = ast.Assign(
            targets=[iter_var],
            value=ast.Call(
                func=ast.Name(id='iter', ctx=ast.Load()),
                args=[node.iter],
                keywords=[]
            )
        )

        # 创建一个变量来存储next()的结果
        target = node.target
        target_assign = ast.Assign(
            targets=[target],
            value=ast.Call(
                func=ast.Name(id='next', ctx=ast.Load()),
                args=[ast.Name(id=iter_var.id, ctx=ast.Load())],
                keywords=[]
            )
        )

        # try-except结构，捕获StopIteration以退出循环
        try_except = ast.Try(
            body=[target_assign] + node.body,
            handlers=[
                ast.ExceptHandler(
                    type=ast.Name(id='StopIteration', ctx=ast.Load()),
                    name=None,
                    body=[ast.Break()]
                )
            ],
            orelse=[],
            finalbody=[]
        )

        # while True:
        while_loop = ast.While(
            test=ast.Constant(value=True),
            body=[try_except],
            orelse=[]
        )

        # 标记代码被修改
        self.modified = True

        # 返回新的代码块：迭代器赋值 + while循环
        return [iter_assign, while_loop]

def convert_for_to_while(source_code):
    """
    将源代码中的所有for循环转换为while循环。
    """
    # 解析源代码为AST
    tree = ast.parse(source_code)

    # 转换AST
    transformer = ForToWhileTransformer()
    transformed_tree = transformer.visit(tree)

    if transformer.modified:
        # 修复缺失的位置信息
        ast.fix_missing_locations(transformed_tree)

        # 将AST转换回源代码
        return astor.to_source(transformed_tree), True
    else:
        # 如果没有修改，返回原代码
        return source_code, False

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="将文件夹中的Python代码中的for循环转换为while循环，仅在有更改时加上-1。")
    parser.add_argument("input_folder", help="输入的Python源代码文件夹")
    parser.add_argument("output_folder", help="输出转换后的Python源代码文件夹")
    args = parser.parse_args()

    # 确保输出文件夹存在
    os.makedirs(args.output_folder, exist_ok=True)

    # 遍历输入文件夹中的所有文件
    for root, _, files in os.walk(args.input_folder):
        for file in files:
            if file.endswith(".py"):  # 仅处理 .py 文件
                input_file_path = os.path.join(root, file)
                relative_path = os.path.relpath(input_file_path, args.input_folder)

                # 读取输入文件
                with open(input_file_path, 'r', encoding='utf-8') as f:
                    source_code = f.read()

                # 转换代码
                converted_code, modified = convert_for_to_while(source_code)

                # 确定输出文件名
                if modified:
                    # 如果内容有变化，文件名加上 `-1`
                    file_name, file_ext = os.path.splitext(relative_path)
                    output_file_name = f"{file_name}{file_ext}"
                else:
                    # 如果内容没有变化，保持原文件名
                    output_file_name = relative_path

                output_file_path = os.path.join(args.output_folder, output_file_name)

                # 确保输出文件夹的子目录结构存在
                os.makedirs(os.path.dirname(output_file_path), exist_ok=True)

                # 写入输出文件
                with open(output_file_path, 'w', encoding='utf-8') as f:
                    f.write(converted_code)

                if modified:
                    print(f"已转换并加上-1: {input_file_path} -> {output_file_path}")
                else:
                    print(f"未发生更改: {input_file_path} -> {output_file_path}")

    print(f"转换完成，所有文件已保存到：{args.output_folder}")

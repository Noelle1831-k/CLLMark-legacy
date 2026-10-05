import argparse
import ast
import os
import astor  # 如果使用 Python < 3.9，需要安装 astor: pip install astor
import sys

class ListCompTransformer(ast.NodeTransformer):
    def __init__(self):
        self.tree_modified = False

    def visit_Assign(self, node):
        """
        处理赋值语句，如果赋值的值是列表推导式且只有一个目标变量，则将其转换为for循环
        """
        # 仅处理单目标赋值
        if len(node.targets) != 1:
            return node

        # 检查赋值的值是否为列表推导式
        if isinstance(node.value, ast.ListComp):
            self.tree_modified = True
            list_comp = node.value
            target = node.targets[0]

            # 创建一个新的赋值语句，将目标初始化为空列表
            new_assign = ast.Assign(
                targets=[target],
                value=ast.List(elts=[], ctx=ast.Load())
            )
            ast.copy_location(new_assign, node)

            # 创建for循环
            loop = self.create_for_loop(target, list_comp)

            return [new_assign, loop]

        return node

    def create_for_loop(self, target, list_comp):
        """
        根据列表推导式的信息，创建等效的for循环
        """
        # 创建循环体：target.append(<elt>)
        append_call = ast.Expr(
            value=ast.Call(
                func=ast.Attribute(
                    value=target,
                    attr='append',
                    ctx=ast.Load()
                ),
                args=[list_comp.elt],
                keywords=[]
            )
        )
        ast.copy_location(append_call, list_comp)

        # 构建嵌套的for循环和if语句
        current = append_call
        # 反向处理生成器，以构建嵌套循环
        for generator in reversed(list_comp.generators):
            # 处理if条件
            ifs = generator.ifs
            if ifs:
                # 多个if条件需要嵌套
                for if_cond in reversed(ifs):
                    current = ast.If(
                        test=if_cond,
                        body=[current],
                        orelse=[]
                    )
                    ast.copy_location(current, generator)

            # 处理for循环
            current = ast.For(
                target=generator.target,
                iter=generator.iter,
                body=[current],
                orelse=[]
            )
            ast.copy_location(current, generator)

        return current

def transform_list_comprehensions(source_code):
    """
    将源代码中的列表推导式转换为for循环，仅在赋值语句中且只有一个目标变量时进行转换
    """
    tree = ast.parse(source_code)
    transformer = ListCompTransformer()
    transformed_tree = transformer.visit(tree)

    if transformer.tree_modified:
        ast.fix_missing_locations(transformed_tree)

    # 始终使用 astor.to_source 进行反解析
    transformed_code = astor.to_source(transformed_tree)

    return transformed_code, transformer.tree_modified

# 示例使用
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="将文件夹中的Python代码中的列表推导式转换为for循环，仅在有更改时加上-1。")
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
                converted_code, modified = transform_list_comprehensions(source_code)

                # 确定输出文件名
                if not modified:
                    # 如果内容没有变化，保持原文件名
                    output_file_path = os.path.join(args.output_folder, relative_path)
                else:
                    # 如果内容有变化，文件名加上 -1
                    file_name, file_ext = os.path.splitext(relative_path)
                    output_file_name = f"{file_name}-1{file_ext}"
                    output_file_path = os.path.join(args.output_folder, output_file_name)

                # 确保输出文件夹的子目录结构存在
                os.makedirs(os.path.dirname(output_file_path), exist_ok=True)

                # 写入输出文件
                with open(output_file_path, 'w', encoding='utf-8') as f:
                    f.write(converted_code)

                if not modified:
                    print(f"未发生更改: {input_file_path} -> {output_file_path}")
                else:
                    print(f"已转换并加上-1: {input_file_path} -> {output_file_path}")

    print(f"转换完成，所有文件已保存到：{args.output_folder}")



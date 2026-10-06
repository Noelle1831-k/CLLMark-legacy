import os
import json

# 指定 JSONL 文件路径和保存文件夹路径
jsonl_file = 'corpus/dataset/Jsonl/mbcpp_release_v1.2.jsonl'  # 替换为 JSONL 文件路径
output_folder = 'MBCPP_H'  # 代码保存的文件夹

# 确保输出文件夹存在
os.makedirs(output_folder, exist_ok=True)

# 读取 JSONL 文件并处理
with open(jsonl_file, 'r', encoding='utf-8') as file:
    for line in file:
        # 解析 JSON 行
        data = json.loads(line.strip())

        # 提取 task_id 和 completion（代码部分）
        task_id = data.get("task_id")
        code = data.get("canonical_solution")

        # 确保 task_id 和代码部分存在
        if task_id and code:
                # 生成文件名 (如 MBPP_61.py)
                file_name = f"{task_id.replace('/', '_').replace('/', '_')}.cpp"
                file_path = os.path.join(output_folder, file_name)

                # 保存代码到文件
                with open(file_path, 'w', encoding='utf-8') as code_file:
                    code_file.write(code)
                print(f"代码已保存到: {file_path}")

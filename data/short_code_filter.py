import os
import re

def process_files_in_folder(folder_path, file_extension, process_function):
    """
    遍历文件夹中的文件并对符合条件的文件进行处理。

    :param folder_path: 目标文件夹路径
    :param file_extension: 文件扩展名（如 '.c' 或 '.h'）
    :param process_function: 对文件内容进行处理的函数，接受文件路径和文件内容作为参数
    """
    for root, _, files in os.walk(folder_path):
        for file in files:
            if file.endswith(file_extension):
                file_path = os.path.join(root, file)
                try:
                    # 读取文件内容
                    with open(file_path, 'r', encoding='utf-8') as f:
                        lines = f.readlines()

                    # 使用处理函数对内容进行修改
                    new_lines = process_function(file_path, lines)

                    # 如果内容有修改，则写回文件
                    if new_lines is not None:
                        with open(file_path, 'w', encoding='utf-8') as f:
                            f.writelines(new_lines)

                except Exception as e:
                    print(f"Error processing file {file_path}: {e}")

def remove_blank_lines(file_path, lines):
    """
    去除文件中的空白行。

    :param file_path: 文件路径（仅用于打印日志）
    :param lines: 文件内容（列表，每行作为一个元素）
    :return: 去除空白行后的内容
    """
    non_blank_lines = [line for line in lines if line.strip()]
    print(f"Processed: {file_path} (Removed {len(lines) - len(non_blank_lines)} blank lines)")
    return non_blank_lines

def remove_block(file_path, lines):
    """
    移除包含```或```C这样的行。

    :param file_path: 文件路径（仅用于打印日志）
    :param lines: 文件内容（列表，每行作为一个元素）
    :return: 去除目标行后的内容
    """
    non_block_lines = [line for line in lines if not re.match(r'^```(?:C|c)?$', line.strip())]
    non_block_lines = [line for line in lines if not re.match(r'^\'\'\'(?:C|c)?$', line.strip())]
    print(f"Processed: {file_path} (Removed {len(lines) - len(non_block_lines)} block lines)")
    return non_block_lines

def remove_import_lines(file_path, lines):
    """
    去除文件中的#include行。

    :param file_path: 文件路径（仅用于打印日志）
    :param lines: 文件内容（列表，每行作为一个元素）
    :return: 去除#include行后的内容
    """
    non_import_lines = [line for line in lines if not line.strip().startswith("#include")]
    print(f"Processed: {file_path} (Removed {len(lines) - len(non_import_lines)} include lines)")
    return non_import_lines

def delete_short_files(file_path, lines, min_lines):
    """
    删除行数少于指定值的文件。

    :param file_path: 文件路径
    :param lines: 文件内容（列表，每行作为一个元素）
    :param min_lines: 最小行数
    :return: None（返回 None 表示文件将被删除）
    """
    if len(lines) < min_lines:
        print(f"Deleting file: {file_path} (Lines: {len(lines)})")
        os.remove(file_path)
        return None
    return lines  # 如果文件不被删除，则返回原内容

def remove_comments_from_file(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            content = file.read()

        if file_path.endswith('.py'):
            # Remove Python comments
            content = re.sub(r'(?m)#.*$', '', content)  # Single-line comments
            content = re.sub(r'(?s)""".*?"""', '', content)  # Multi-line comments
            content = re.sub(r"(?s)\'\'\'.*?\'\'\'", '', content)  # Multi-line comments

        elif file_path.endswith('.cpp'):
            # Remove C++ comments
            content = re.sub(r'(?m)//.*$', '', content)  # Single-line comments
            content = re.sub(r'(?s)/\*.*?\*/', '', content)  # Multi-line comments
            content = re.sub(r"(?s)\'\'\'.*?\'\'\'", '', content)  # Multi-line comments
        elif file_path.endswith('.c') or file_path.endswith('.h'):
            # Remove C comments
            content = re.sub(r'(?m)//.*$', '', content)  # Single-line comments
            content = re.sub(r'(?s)/\*.*?\*/', '', content)  # Multi-line comments
            content = re.sub(r"(?s)\'\'\'.*?\'\'\'", '', content)  # Multi-line comments

        # Write back the modified content
        with open(file_path, 'w', encoding='utf-8') as file:
            file.write(content)

        print(f"Comments removed from: {file_path}")

    except Exception as e:
        print(f"Error processing file {file_path}: {e}")

def clean_folder_of_comments(folder_path):
    for root, _, files in os.walk(folder_path):
        for file in files:
            if file.endswith('.py') or file.endswith('.cpp') or file.endswith('.c') or file.endswith('.h'):
                file_path = os.path.join(root, file)
                remove_comments_from_file(file_path)

# 使用示例
folder_path = "WareHouse_C++"  # 替换为目标文件夹路径
EXT = 'cpp'
# 清除文件中的注释
clean_folder_of_comments(folder_path)

# 清除 .c 文件中的空白行
process_files_in_folder(folder_path, f'.{EXT}', remove_blank_lines)

# 移除包含```或```C的行
process_files_in_folder(folder_path, f'.{EXT}', remove_block)

# 清除 .c 文件中的#include行
# process_files_in_folder(folder_path, f'.{EXT}', remove_import_lines)

# 删除少于 6 行的 .c 文件
# process_files_in_folder(folder_path, f'.{EXT}', lambda file_path, lines: delete_short_files(file_path, lines, min_lines=8))

import time
import chardet
import os
import difflib
from change_program_style import SCTS
import transform_list_comprehensions
import fortowhile
# import folder_to_jsonl

import hashlib

dict_lang = {
    'python': '.py',
    'cpp': '.cpp',
    'c': '.c'  # Fixed extension for 'c'
}


def read_file_with_auto_encoding(file_path):
    with open(file_path, "rb") as file:
        raw_data = file.read()
        result = chardet.detect(raw_data)
        encoding = result['encoding']

        if encoding is None:
            raise ValueError("无法检测文件编码")

    with open(file_path, "r", encoding=encoding) as file:
        return file.read()


def write_to_new_file(new_file_path, content, encoding="utf-8"):
    os.makedirs(os.path.dirname(new_file_path), exist_ok=True)
    with open(new_file_path, "w", encoding=encoding) as file:
        file.write(content)


def read_file_lines(file_path):
    with open(file_path, "r", encoding="utf-8") as file:
        return file.readlines()


def process_directory(input_dir, output_dir, transform_sequence, lang, see_tree):
    scts = SCTS(f"{lang}")
    try:
        for root, _, files in os.walk(input_dir):
            for file in files:
                if file.endswith(f"{dict_lang[lang]}"):
                    input_file_path = os.path.join(root, file)
                    relative_path = os.path.relpath(input_file_path, input_dir)

                    output_file_path = os.path.join(output_dir, relative_path)
                    base, ext = os.path.splitext(output_file_path)
                    print(f"Processing file: {input_file_path}")

                    file_content = read_file_with_auto_encoding(input_file_path)
                    dict_func = scts.get_func_block(transform_sequence, file_content)

                    if see_tree:
                        scts.see_tree(file_content)

                    for func_name, func_block in dict_func.items():
                        # Construct the new file name with the same extension
                        func_file_name = func_name + dict_lang[lang]

                        # Determine the relative directory of the current file
                        func_relative_dir = os.path.dirname(relative_path)

                        # Construct the full path for the function file
                        func_output_dir = os.path.join(output_dir, func_relative_dir)
                        func_output_path = os.path.join(func_output_dir, func_file_name)

                        # Write the function block to the new file
                        write_to_new_file(func_output_path, func_block)
                        print(f"Saved function '{func_name}' to: {func_output_path}")

    except Exception as e:
        print(f"处理目录失败: {e}")


see_tree = 0
lang = 'cpp'
input_directory = "WareHouse_C++"
output_directory = "corpus/C++_func"

transform_sequence_list = ['13']

for transform_sequence in transform_sequence_list:
    process_directory(input_directory, output_directory, transform_sequence, lang, see_tree)



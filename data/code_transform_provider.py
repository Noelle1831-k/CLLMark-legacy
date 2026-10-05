import re
import sys
import time

import chardet
import os
import difflib
from change_program_style import SCTS
#import transform_list_comprehensions
import fortowhile
#import folder_to_jsonl


import os
import hashlib


dict_lang={
    'python':'.py',
    'cpp':'.cpp',
    'c':'c'
}


import json
def read_jsonl(file):
    with open(file, 'r') as file:
        for line in file:
            line = line.strip()
            data = json.loads(line.replace("'", "\""))
            return data.get('pass@1')



def get_num(directory):
    file_count = 0
    for root, dirs, files in os.walk(directory):
        file_count += len(files)
    return file_count

def calculate_file_hash(file_path):
    """计算文件的哈希值（使用 SHA-256）"""
    hash_func = hashlib.sha256()
    try:
        with open(file_path, 'rb') as f:
            while chunk := f.read(8192):  # 逐块读取文件
                hash_func.update(chunk)
    except FileNotFoundError:
        return None
    return hash_func.hexdigest()

def compare_folders(folder1, folder2):
    """对比两个文件夹内的同名文件，统计内容改变和未改变的文件个数"""
    changed_count = 0
    unchanged_count = 0

    # 获取两个文件夹中的所有文件名
    files1 = set(os.listdir(folder1))
    files2 = set(os.listdir(folder2))

    # 找到两个文件夹中共有的文件名
    common_files = files1 & files2

    for file_name in common_files:
        file1_path = os.path.join(folder1, file_name)
        file2_path = os.path.join(folder2, file_name)

        # 计算两个文件的哈希值
        hash1 = calculate_file_hash(file1_path)
        hash2 = calculate_file_hash(file2_path)

        if hash1 is None or hash2 is None:
            print(f"Error reading file: {file_name}")
            continue

        # 比较哈希值判断文件内容是否相同
        if hash1 == hash2:
            unchanged_count += 1
        else:
            changed_count += 1

    return changed_count, unchanged_count


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



def display_diff_in_console(before_file, after_content):
    # before_lines = read_file_lines(before_file)
    before_lines = before_file.splitlines(keepends=True)
    after_lines = after_content.splitlines(keepends=True)


    diff = difflib.unified_diff(
        before_lines, after_lines,
        fromfile="Before Processing",
        tofile="After Processing",
        lineterm=""
    )

    # 打印结果
    for line in diff:
        print(line)



def process_directory(input_dir, output_dir, transform_sequence,lang,see_tree):
    print(transform_sequence)
    total_time = 0.0
    succ_num = 0
    transform_num = 0
    transform_num_total = 0
    scts = SCTS(f"{lang}")
    try:
        for root, _, files in os.walk(input_dir):
            for file in files:
                if file.endswith(f"{dict_lang[lang]}"):
                    input_file_path = os.path.join(root, file)
                    relative_path = os.path.relpath(input_file_path, input_dir)

                    output_file_path = os.path.join(output_dir, relative_path)
                    base, ext = os.path.splitext(output_file_path)
                    success_file_path = f"{base}{ext}"
                    normal_file_path = f"{base}{ext}"
                    #print(f"Processing file: {input_file_path}")

                    file_content = read_file_with_auto_encoding(input_file_path)
                    start_time = time.perf_counter()
                    if transform_sequence not in ['11','12']:
                        new_code, success,transform_num = scts.change_file_style(transform_sequence, file_content)
                        # dict_func = scts.get_func_block(transform_sequence,file_content)
                        # print(dict_func)
                        if see_tree == True:
                            scts.see_tree(file_content)
                    elif transform_sequence == '11':
                        new_code, success = fortowhile.convert_for_to_while(file_content)
                    #elif transform_sequence == '12':
                        #new_code, success = transform_list_comprehensions.transform_list_comprehensions(file_content)
                    end_time = time.perf_counter()
                    total_time += end_time - start_time
                    transform_num_total += transform_num
                    if success and file_content != new_code:
                        succ_num += 1
                        write_to_new_file(success_file_path, new_code)
                        display_diff_in_console(file_content, new_code)
                        print(f"Processed successfully: {input_file_path}")
                    # elif file_content == new_code:
                    #     write_to_new_file(success_file_path,new_code)
                    #     #print(f"No changes detected for file: {input_file_path}")
                    # else:
                    #     write_to_new_file(success_file_path, new_code)
                    #     #print(f"Failed to process file: {input_file_path}")

    except Exception as e:
        print(f"处理目录失败: {e}")
    return total_time,succ_num,transform_num_total


if __name__ == "__main__":
    see_tree = 1
    lang = 'c'
    input_directory = "test"
    output_directory = "test_1"
    # json_dir = "Z:/output_c.jsonl"
    transform_sequence_list_py = ['11','7.8','7.3','7.4','7.1','7.6','7.9','1.1','1.3','7.5','7.10','7.11','4.1','4.3','3.3',
                                    '6.2','6.3','10.2','10.4']

    transform_sequence_list_cpp = ['7.8','7.7','8.3','8.1','6.1','6.5','3.4','2.7','2.6','2.3','2.4']
    transform_sequence_list_c = ['7.8','7.7','5.1','5.3','6.1','6.5','3.4','2.7','2.6','2.3','2.4']
    transform_sequence_list = ['5.4']
    Time = 0.0
    Succ_total = 0
    Transform_num = 0
    succ_per = 0.0
    #transform_sequence_list_c = ['7.8','7.7','5.1','5.3','6.1','6.5','3.4','2.7','2.6','2.3','2.4']
    for transform_sequence in transform_sequence_list:
        Total_time,Succ_num,transform_num = process_directory(input_directory, output_directory, transform_sequence,lang,see_tree)
        Time += Total_time
        Succ_total += Succ_num
        Transform_num += transform_num
        Total_num = get_num(input_directory)
        #changed,unchanged = compare_folders('MBCPP_G', 'dataset/MBCPP_H')
        #print(f'changed:{changed},unchanged:{unchanged}')
        #folder_to_jsonl.convert_py_folder_to_jsonl('test_1','output_json.jsonl','python','py')
        print(f'Avg_Time:{Time/Total_num* 1000} ms,Total_Time:{Time},Total_Tum : {Total_num},Total_Succ:{Succ_total},transform_num:{Transform_num}')

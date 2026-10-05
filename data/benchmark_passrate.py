import re
import sys
import time

import chardet
import os
import difflib
from change_program_style import SCTS
#import transform_list_comprehensions
import fortowhile
import folder_to_jsonl


import os
import hashlib

from dataset.MBPP_G.MBPP_482 import match

dict_lang={
    'python':'.py',
    'cpp':'.cpp',
    'c':'c'
}

import subprocess


def run_command_popen(command):
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = process.communicate()
    return stdout


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
                    file_content = read_file_with_auto_encoding(input_file_path)
                    start_time = time.perf_counter()
                    if transform_sequence == '11':
                        new_code, success,transform_num = scts.change_file_style(transform_sequence, file_content)
                        if see_tree == True:
                            scts.see_tree(file_content)
                    elif transform_sequence == '11':
                        new_code, success = fortowhile.convert_for_to_while(file_content)
                    end_time = time.perf_counter()
                    total_time += end_time - start_time
                    transform_num_total += transform_num
                    if success and file_content != new_code:
                        succ_num += 1
                        write_to_new_file(success_file_path, new_code)
                    elif file_content == new_code:
                        write_to_new_file(success_file_path,new_code)
                    else:
                        write_to_new_file(success_file_path, new_code)

    except Exception as e:
        print(f"处理目录失败: {e}")
    return total_time,succ_num,transform_num_total
see_tree = 0
lang = 'python'
input_directory = "dataset/MBPP_G"
output_directory = "test_1"
json_dir = "Z:/output_c.jsonl"
transform_sequence_list_py = ['11','7.8','7.3','7.4','7.1','7.6','7.9','1.1','1.3','7.5','7.10','7.11','4.1','4.3','3.3','6.2','6.3','10.2','10.4']
transform_sequence_list_cpp = ['7.8','7.7','6.1','6.5','3.4','2.7','2.6','2.3','2.4']
transform_sequence_list_c = ['7.8','7.7','5.1','5.3','6.1','6.5','3.4','2.7','2.6','2.3','2.4']
Time = 0.0
Succ_total = 0
Transform_num = 0
succ_per = 0.0
Total_num = get_num(input_directory)
for transform_sequence in transform_sequence_list_py:
    Total_time,Succ_num,transform_num = process_directory(input_directory, output_directory, transform_sequence,lang,see_tree)
    Time += Total_time
    Succ_total += Succ_num
    Transform_num += transform_num
    folder_to_jsonl.convert_py_folder_to_jsonl('test_1','output_json.jsonl',f'{lang}',f"{dict_lang[lang]}")
    run_command_popen("conda activate ChatDev_conda_env")
    out = run_command_popen("evaluate_functional_correctness /home/ps/data/output_json.jsonl --problem_file /home/ps/mxeval/data/mbxp/mbpp_release_v1.jsonl"
    )
    match = read_jsonl('output_json.jsonl_passatk.json')
    print(match)
    succ_per += float(match)
print(f'Avg_Time:{Time/Total_num* 1000} ms,Total_Time:{Time},pass:{succ_per/len(transform_sequence_list_py)}')
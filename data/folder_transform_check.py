import difflib
import shutil

import chardet
import numpy as np
from tqdm import tqdm

from change_program_style import SCTS
import fortowhile
import rule_dict
import os
import hashlib
import matplotlib.pyplot as plt


dict_lang={
    'python':'.py',
    'cpp':'.cpp',
    'c':'c'
}

import subprocess
import json


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



def get_sorted_files_by_sha256(directory):
    all_items = os.listdir(directory)
    file_list = [f for f in all_items if os.path.isfile(os.path.join(directory, f)) and '.json' not in f]
    file_list.sort(key = lambda x: hashlib.sha256(x.encode('utf-8')).hexdigest())

    return file_list


def read_file_with_auto_encoding(file_path):
    with open(file_path, "rb") as file:
        raw_data = file.read()
        result = chardet.detect(raw_data)
        encoding = result['encoding']

        if encoding is None:
            raise ValueError("无法检测文件编码")


    with open(file_path, "r", encoding=encoding) as file:
        return file.read()


def check_file_rule(input_file_path,transform_sequence,lang,see_tree):
    scts = SCTS(f"{lang}")
    file_content = read_file_with_auto_encoding(input_file_path)
    success = False
    try:
        if transform_sequence not in ['11','12']:
            new_code, success,transform_num = scts.change_file_style(transform_sequence, file_content)
            if success and file_content != new_code:
                # display_diff_in_console(file_content, new_code)
                return True
            else:
                return False
        else:
            if transform_sequence == '11':
                check_style = '7.7'
                node_num = scts.get_file_popularity(check_style, file_content)
            elif transform_sequence == '12':
                check_style = '7.8'
                node_num = scts.get_file_popularity(check_style, file_content)
            if transform_sequence in ['11','12'] and node_num > 0:
                return True
            else:
                return False
    except Exception as e:
        print(input_file_path)
        print(transform_sequence)
        print(f"处理目录失败: {e}")


def check_support_transform(lang,input_directory) -> int:
    ret = {}
    see_tree = 0
    trans_num = 0
    file_list = get_sorted_files_by_sha256(input_directory)
    lang_rule_dict = rule_dict.rule_dict[lang]
    i = 0
    for file in file_list:
        file_support = []
        file_path = os.path.join(input_directory,file)
        for name,rule_list in lang_rule_dict.items():
            for rule in rule_list:
                if rule not in ['_','']:
                    success = check_file_rule(file_path,rule,lang,see_tree)
                    if success:
                        file_support.append(name)
                        break
        ret[file] = file_support
        trans_num += len(file_support)
        if(len(file_support) == 0):
            i += 1
    print(i)
    with open(f'{input_directory}/support_transform.json','w',encoding='utf-8') as f:
        json.dump(ret,f,ensure_ascii=False,indent=4)
    return trans_num

def get_subfolder(directory):
    return [item for item in os.listdir(directory) if os.path.isdir(os.path.join(directory,item))]

if __name__ == "__main__":
    directory = 'C_func_test2'
    lang = 'c'
    num_list = []
    # max_num = 0
    # max_folder = ''
    for folder in tqdm(get_subfolder(directory),desc = "Extracting support transform in subfolder",unit = "item"):
        trans_num = check_support_transform(lang,os.path.join(directory,folder))
        if trans_num < 7:
            tqdm.write(f'\n{folder} has too few available transforms(Less than 7).')
            shutil.rmtree(os.path.join(directory,folder))
        num_list.append(trans_num)
        # if trans_num > max_num:
        #     max_num = trans_num
        #     max_folder = folder
    # print(max_folder,max_num)
    # bins = np.arange(0,100,1)
    # plt.hist(num_list,bins=bins,edgecolor = "black",alpha = 0.7)
    # plt.xlabel("Range")
    # plt.ylabel("Fre")
    # plt.show()
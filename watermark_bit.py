import json
from collections import deque

import chardet

from tqdm import tqdm

from change_program_style import SCTS
import rule_dict_bit_acc
import os
import bch_utils
from folder_transform_check import display_diff_in_console

dict_lang = {
    'python': '.py',
    'cpp': '.cpp',
    'c': 'c'
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


def transform_on_file(input_file_path, transform_sequence, lang, see_tree):
    scts = SCTS(f"{lang}")
    file_content = read_file_with_auto_encoding(input_file_path)
    success = False
    try:
        if transform_sequence in ['11', '12']:
            return True
        new_code, success, transform_num = scts.change_file_style(transform_sequence, file_content)
        if see_tree:
            scts.see_tree(file_content)
        if success and file_content != new_code:
            write_to_new_file(input_file_path, new_code)
            display_diff_in_console(file_content, new_code)
            print(input_file_path)
            return True
        else:
            return False
    except Exception as e:
        print(input_file_path)
        print(f"处理目录失败: {e}")


def read_json(file):
    with open(file, 'r', encoding='utf-8') as f:
        data = json.load(f)
    return data


def get_trans_num(rule, bit, language):
    bit_num = rule_dict_bit_acc.rule_dict[lang][rule][bit]
    return bit_num


def get_subfolder(directory):
    return [item for item in os.listdir(directory) if os.path.isdir(os.path.join(directory, item))]


def folder_bit_watermark(bit_list, directory, lang, see_tree):
    encoded_bit = bch_utils.encode_bch_7_4(bit_list)
    queue = deque(encoded_bit)
    print(queue)
    available_trans_dict = read_json(os.path.join(os.path.join(directory, 'support_transform.json')))
    for file_name, available_trans_list in available_trans_dict.items():
        if len(available_trans_list) > 0:
            for rule in available_trans_list:
                if len(queue) == 0:
                    break
                bit = queue.popleft()
                trans_num = get_trans_num(rule, bit, lang)
                print(trans_num, rule)
                transform_on_file(os.path.join(directory, file_name), trans_num, lang, see_tree)


if __name__ == '__main__':
    see_tree = 0
    lang = 'python'
    bit_list = [1, 0, 1, 0]
    directory = 'Python_func_test'
    for folder in tqdm(get_subfolder(directory), desc=f"Watermarking bits:{bit_list} in subfolder", unit="item"):
        folder_bit_watermark(bit_list, os.path.join(directory, folder), lang, see_tree)

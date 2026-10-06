import os

from tqdm import tqdm

from change_program_style import SCTS
from folder_transform_check import get_subfolder, load_project
from watermark_bit import read_json
import watermark_core


def folder_bit_extract(bit_list, directory, lang, see_tree=False):
    """Return (decoded message == bit_list, raw extracted codeword == expected codeword)."""
    support = read_json(os.path.join(directory, 'support_transform.json'))
    files = load_project(directory, watermark_core.slot_files(support, bit_list))
    scts = SCTS(lang)
    if see_tree:
        for code in files.values():
            scts.see_tree(code)
    return watermark_core.extract(scts, lang, files, support, bit_list)


if __name__ == '__main__':
    lang = 'python'
    bit_list = [1, 0, 1, 0]
    directory = 'corpus/Python_func_test'
    succ = ori_succ = fail = ori_fail = 0
    for folder in tqdm(get_subfolder(directory), desc=f"Extracting bits:{bit_list} in subfolder", unit="item"):
        result, ori_result = folder_bit_extract(bit_list, os.path.join(directory, folder), lang)
        succ, fail = succ + result, fail + (not result)
        ori_succ, ori_fail = ori_succ + ori_result, ori_fail + (not ori_result)
        if not ori_result:
            print(folder)
    print(succ, fail, ori_succ, ori_fail)

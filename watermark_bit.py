import json
import os

from tqdm import tqdm

from change_program_style import SCTS
from code_io import write_source
from folder_transform_check import get_subfolder, load_project
import watermark_core


def read_json(file):
    with open(file, 'r', encoding='utf-8') as f:
        return json.load(f)


def folder_bit_watermark(bit_list, directory, lang, see_tree=False):
    """Embed the BCH codeword of bit_list into the directory's files in place."""
    support = read_json(os.path.join(directory, 'support_transform.json'))
    files = load_project(directory, watermark_core.slot_files(support, bit_list))
    scts = SCTS(lang)
    if see_tree:
        for code in files.values():
            scts.see_tree(code)
    for name, code in watermark_core.embed(scts, lang, files, support, bit_list).items():
        write_source(os.path.join(directory, name), code)


if __name__ == '__main__':
    lang = 'python'
    bit_list = [1, 0, 1, 0]
    directory = 'Python_func_test'
    for folder in tqdm(get_subfolder(directory), desc=f"Watermarking bits:{bit_list} in subfolder", unit="item"):
        folder_bit_watermark(bit_list, os.path.join(directory, folder), lang)

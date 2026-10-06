import difflib
import json
import os
import shutil

from tqdm import tqdm

from change_program_style import SCTS
from code_io import read_source
import watermark_core


def display_diff_in_console(before_file, after_content):
    diff = difflib.unified_diff(
        before_file.splitlines(keepends=True), after_content.splitlines(keepends=True),
        fromfile="Before Processing", tofile="After Processing", lineterm="")
    for line in diff:
        print(line)


def read_file_with_auto_encoding(file_path):
    return read_source(file_path)


def load_project(directory, names=None):
    """Decode the project's files once: all regular non-JSON files, or only `names`."""
    if names is None:
        names = [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]
    return {name: read_source(os.path.join(directory, name)) for name in watermark_core.project_order(names)}


def check_support_transform(lang, input_directory) -> int:
    """Write the directory's support_transform.json and return its total slot capacity."""
    support = watermark_core.analyze(SCTS(lang), lang, load_project(input_directory))
    with open(f'{input_directory}/support_transform.json', 'w', encoding='utf-8') as f:
        json.dump(support, f, ensure_ascii=False, indent=4)
    print(sum(not rules for rules in support.values()))
    return sum(len(rules) for rules in support.values())


def get_subfolder(directory):
    return [item for item in os.listdir(directory) if os.path.isdir(os.path.join(directory, item))]


if __name__ == "__main__":
    directory = 'corpus/Python_func_test'
    lang = 'python'
    for folder in tqdm(get_subfolder(directory), desc="Extracting support transform in subfolder", unit="item"):
        trans_num = check_support_transform(lang, os.path.join(directory, folder))
        if trans_num < 7:
            tqdm.write(f'\n{folder} has too few available transforms(Less than 7).')
            shutil.rmtree(os.path.join(directory, folder))

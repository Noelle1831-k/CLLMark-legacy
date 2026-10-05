import re

def replace_spaces(text):
    return re.sub('\\s', '_', text)
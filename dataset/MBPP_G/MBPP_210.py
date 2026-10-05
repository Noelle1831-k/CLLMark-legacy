import re

def is_allowed_specific_char(string):
    pattern = re.compile('^[a-zA-Z0-9]+$')
    return bool(pattern.match(string))
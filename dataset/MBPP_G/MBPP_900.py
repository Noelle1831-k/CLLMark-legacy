import re

def match_num(string):
    pattern = '^5.*'
    return bool(re.match(pattern, string))
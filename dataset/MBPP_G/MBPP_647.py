import re

def split_upperstring(text):
    return re.findall('[A-Z][a-z]*', text)
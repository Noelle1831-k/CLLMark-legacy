import re

def find_char(text):
    return re.findall('\\b\\w{3,5}\\b', text)
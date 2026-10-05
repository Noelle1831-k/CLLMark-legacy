import re

def find_long_word(text):
    return re.findall('\\b\\w{5}\\b', text)
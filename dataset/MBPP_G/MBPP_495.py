import re

def remove_lowercase(str1):
    return ''.join(re.findall('[A-Z]+', str1))
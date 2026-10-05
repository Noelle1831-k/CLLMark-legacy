import re

def is_decimal(num):
    return bool(re.fullmatch('\\d+\\.\\d{1,2}', num))
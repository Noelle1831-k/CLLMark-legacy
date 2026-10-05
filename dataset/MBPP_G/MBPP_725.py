import re

def extract_quotation(text1):
    return re.findall('"(.*?)"', text1)
import re

def extract_max(input):
    numbers = re.findall('\\d+', input)
    return max(map(int, numbers)) if numbers else 0
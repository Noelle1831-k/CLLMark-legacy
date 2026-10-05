import re

def remove_spaces(text):
    return re.sub('\\s+', ' ', text)
import re

def remove_char(S):
    return re.sub('[^a-zA-Z0-9]', '', S)
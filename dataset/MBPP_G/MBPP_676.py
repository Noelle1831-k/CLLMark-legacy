import re

def remove_extra_char(text1):
    return re.sub('[^a-zA-Z0-9]', '', text1)
import re

def text_lowercase_underscore(text):
    pattern = '^[a-z]+_[a-z]+$'
    if re.match(pattern, text):
        return 'Found a match!'
    else:
        return 'Not matched!'
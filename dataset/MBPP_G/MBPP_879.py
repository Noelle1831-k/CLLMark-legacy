import re

def text_match(text):
    if re.search('a.*b$', text):
        return 'Found a match!'
    else:
        return 'Not matched!'
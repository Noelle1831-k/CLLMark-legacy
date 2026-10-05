import re

def match(text):
    if re.search('[A-Z][a-z]+', text):
        return 'Yes'
    else:
        return 'No'
import re

def check_alphanumeric(string):
    if re.search('[a-zA-Z0-9]$', string):
        return 'Accept'
    return 'Discard'
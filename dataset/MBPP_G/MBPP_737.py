import re

def check_str(string):
    if re.match('^[aeiouAEIOU]', string):
        return 'Valid'
    else:
        return 'Invalid'
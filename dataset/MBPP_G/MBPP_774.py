import re

def check_email(email):
    pattern = '^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$'
    if re.match(pattern, email):
        return 'Valid Email'
    return 'Invalid Email'
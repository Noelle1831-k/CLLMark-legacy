def check_literals(text, patterns):
    import re
    for pattern in patterns:
        if re.search(pattern, text):
            return 'Matched!'
    return 'Not Matched!'
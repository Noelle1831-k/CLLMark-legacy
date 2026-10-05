def string_literals(patterns, text):
    for pattern in patterns:
        if pattern in text:
            return 'Matched!'
    return 'Not Matched!'
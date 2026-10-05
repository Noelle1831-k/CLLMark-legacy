def text_match(text):
    pattern = 'ab*'
    if re.match(pattern, text):
        return 'Found a match!'
    else:
        return 'Not matched!'
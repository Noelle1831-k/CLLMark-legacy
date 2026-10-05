def text_match(text):
    pattern = 'a0*b*'
    if re.fullmatch(pattern, text):
        return 'Found a match!'
    else:
        return 'Not matched!'
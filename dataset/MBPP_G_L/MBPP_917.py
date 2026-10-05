def text_uppercase_lowercase(text):
    pattern = '[A-Z][a-z]+'
    if re.search(pattern, text):
        return 'Found a match!'
    else:
        return 'Not matched!'
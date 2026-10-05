def text_match_wordz(text):
    pattern = '\\b\\w*z\\w*\\b'
    if re.search(pattern, text):
        return 'Found a match!'
    else:
        return 'Not matched!'
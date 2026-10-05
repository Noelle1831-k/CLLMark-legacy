def text_match_one(text):
    pattern = 'ab+'
    if re.search(pattern, text):
        return 'Found a match!'
    else:
        return 'Not matched!'
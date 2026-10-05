def text_match_two_three(text):
    pattern = 'ab{2,3}'
    if re.search(pattern, text):
        return 'Found a match!'
    else:
        return 'Not matched!'
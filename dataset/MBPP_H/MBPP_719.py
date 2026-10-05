from re import search
def text_match(text):
    patterns = 'ab*?'
    if search(patterns, text):
        return 'Found a match!'
    else:
        return 'Not matched!'
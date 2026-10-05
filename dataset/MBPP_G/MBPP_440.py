import re

def find_adverb_position(text):
    match = re.search('\\b\\w+ly\\b', text)
    if match:
        start = match.start()
        end = match.end()
        return (start, end, match.group())
    return None
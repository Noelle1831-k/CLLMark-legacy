import re

def find_adverbs(text):
    matches = []
    for match in re.finditer('\\b\\w+ly\\b', text):
        start, end = match.span()
        matches.append(f'{start}-{end}: {match.group()}')
    return ', '.join(matches) if matches else None
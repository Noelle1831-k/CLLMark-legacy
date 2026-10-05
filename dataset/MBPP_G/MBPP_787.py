def text_match_three(text):
    import re
    if re.search('ab{3}', text):
        return 'Found a match!'
    else:
        return 'Not matched!'
print(text_match_three('ac'))
print(text_match_three('dc'))
print(text_match_three('abbbba'))
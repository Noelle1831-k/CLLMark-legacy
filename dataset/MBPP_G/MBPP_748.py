import re

def capital_words_spaces(str1):
    return re.sub('(?<!^)(?=[A-Z])', ' ', str1)
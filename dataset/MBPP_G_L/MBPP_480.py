def get_max_occuring_char(str1):
    from collections import Counter
    str1 = str1.replace(' ', '')
    char_count = Counter(str1)
    max_occur_char = max(char_count, key=char_count.get)
    return max_occur_char
def first_repeated_word(str1):
    words = str1.split()
    seen = set()
    for word in words:
        if word in seen:
            return word
        seen.add(word)
    return None
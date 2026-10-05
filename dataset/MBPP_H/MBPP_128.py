def long_words(n, string):
    word_len = []
    txt = string.split(" ")
    for x in txt:
        if len(x) > n:
            word_len.append(x)
    return word_len
def long_words(n, str):
    return [word for word in str.split() if len(word) > n]
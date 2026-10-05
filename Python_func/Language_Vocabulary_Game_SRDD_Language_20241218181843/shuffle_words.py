def shuffle_words(language="English"):
    words = load_vocabulary(language)
    random.shuffle(words)
    return words
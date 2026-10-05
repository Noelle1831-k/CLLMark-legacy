def add_word(word, meaning, example):
    """
    Adds a new word to the vocabulary if it doesn't already exist.
    Handles possible errors related to file access.
    """
    vocab = load_vocabulary()
    if word in vocab:
        print(f"'{word}' already exists in the vocabulary.")
    else:
        vocab[word] = {"meaning": meaning, "example": example}
        save_vocabulary(vocab)
        print(f"'{word}' has been added to the vocabulary.")
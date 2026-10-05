def list_words():
    """
    Lists all words in the vocabulary. If there are no words, a message is shown.
    """
    vocab = load_vocabulary()
    if not vocab:
        print("No words in the vocabulary.")
    else:
        for word, details in vocab.items():
            print(f"Word: {word}, Meaning: {details['meaning']}, Example: {details['example']}")
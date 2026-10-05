def save_vocabulary(vocab):
    """
    Saves the vocabulary to the JSON file with proper indentation.
    """
    try:
        with open(VOCAB_FILE, "w") as file:
            json.dump(vocab, file, indent=4)
    except IOError as e:
        print(f"Error saving vocabulary: {e}")
def load_vocabulary():
    """
    Loads vocabulary from the JSON file. If the file is not found or is empty, it returns an empty dictionary.
    """
    try:
        with open(VOCAB_FILE, "r") as file:
            return json.load(file)
    except FileNotFoundError:
        return {}
    except json.JSONDecodeError:
        print("Error: Vocabulary file is corrupted.")
        return {}
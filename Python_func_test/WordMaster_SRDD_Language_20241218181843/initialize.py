def initialize():
    """
    Initializes the application by ensuring necessary files exist.
    """
    if not os.path.exists("vocabulary.json"):
        with open("vocabulary.json", "w") as file:
            file.write("{}")
    if not os.path.exists("progress.json"):
        with open("progress.json", "w") as file:
            file.write('{"score": 0, "words_learned": 0}')
def load_progress():
    """
    Loads progress data from the JSON file.
    """
    try:
        with open(PROGRESS_FILE, "r") as file:
            return json.load(file)
    except FileNotFoundError:
        return {"score": 0, "words_learned": 0}
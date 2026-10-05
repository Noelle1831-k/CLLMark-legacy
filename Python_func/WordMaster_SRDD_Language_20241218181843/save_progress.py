def save_progress(progress):
    """
    Saves progress data to the JSON file.
    """
    with open(PROGRESS_FILE, "w") as file:
        json.dump(progress, file, indent=4)
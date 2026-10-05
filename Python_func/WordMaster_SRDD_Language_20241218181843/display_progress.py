def display_progress():
    """
    Displays the user's progress.
    """
    progress = load_progress()
    print(f"Score: {progress['score']}")
    print(f"Words Learned: {progress['words_learned']}")
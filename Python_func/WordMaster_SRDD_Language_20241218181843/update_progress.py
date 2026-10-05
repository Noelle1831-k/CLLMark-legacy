def update_progress(new_score, new_words):
    """
    Updates user progress.
    """
    progress = load_progress()
    progress["score"] += new_score
    progress["words_learned"] += new_words
    save_progress(progress)
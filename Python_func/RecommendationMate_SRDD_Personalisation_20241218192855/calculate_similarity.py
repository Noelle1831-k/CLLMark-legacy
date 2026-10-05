def calculate_similarity(preferences, movie):
    # Simulate a complex similarity calculation
    score = 0
    for key, value in preferences.items():
        if key in movie and movie[key] == value:
            score += 1
    return score / len(preferences) if preferences else 0
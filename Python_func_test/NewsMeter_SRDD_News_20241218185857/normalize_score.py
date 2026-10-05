def normalize_score(score, min_score=0, max_score=1):
    # Normalize score to a scale of 0 to 100
    normalized_score = (score - min_score) / (max_score - min_score) * 100
    return normalized_score
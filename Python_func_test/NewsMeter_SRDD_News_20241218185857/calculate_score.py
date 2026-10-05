def calculate_score(credibility_factors):
    # Calculate score using a weighted sum of factors
    weights = {
        'source_reliability': 0.4,
        'author_expertise': 0.3,
        'content_quality': 0.2,
        'evidence_support': 0.1
    }
    score = sum(credibility_factors[factor] * weight for factor, weight in weights.items())
    return score
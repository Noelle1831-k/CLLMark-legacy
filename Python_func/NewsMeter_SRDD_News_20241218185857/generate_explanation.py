def generate_explanation(credibility_factors):
    # Generate explanation based on credibility factors
    explanation = (
        f"Source Reliability: {credibility_factors['source_reliability']:.2f}, "
        f"Author Expertise: {credibility_factors['author_expertise']:.2f}, "
        f"Content Quality: {credibility_factors['content_quality']:.2f}, "
        f"Evidence Support: {credibility_factors['evidence_support']:.2f}."
    )
    return explanation
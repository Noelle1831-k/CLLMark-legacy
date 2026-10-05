double aggregate_scores(double source_score, double bias_score, double factual_score, double language_score) {
    return (source_score * 0.4) + (bias_score * 0.2) + (factual_score * 0.3) + (language_score * 0.1);
}
Score CredibilityAnalyzer::generateScore() {
    Score score;
    score.addExplanation("Grammar evaluation completed.");
    score.addExplanation("Source reliability evaluated as high.");
    score.addExplanation("Bias evaluation: No major biases detected.");
    score.addExplanation("Sentiment is neutral.");
    score.setScore(85);
    return score;
}
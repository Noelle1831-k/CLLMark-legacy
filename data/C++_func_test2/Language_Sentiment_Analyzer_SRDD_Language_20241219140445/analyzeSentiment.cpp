string SentimentAnalyzer::analyzeSentiment(const string &text) {
    TextProcessor processor;
    string cleanedText = processor.removeSpecialCharacters(text);
    cleanedText = processor.toLower(cleanedText);
    vector<string> tokens = processor.split(cleanedText, ' ');
    int positiveScore = calculateScore(tokens, dictLoader.getPositiveWords());
    int negativeScore = calculateScore(tokens, dictLoader.getNegativeWords());
    int neutralScore = calculateScore(tokens, dictLoader.getNeutralWords());
    if (positiveScore > negativeScore && positiveScore > neutralScore) {
        return "Positive";
    } else if (negativeScore > positiveScore && negativeScore > neutralScore) {
        return "Negative";
    } else {
        return "Neutral";
    }
}
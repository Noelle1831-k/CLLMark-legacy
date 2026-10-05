int SentimentAnalyzer::calculateScore(const vector<string> &tokens, const vector<string> &dictionary) {
    int score = 0;
    for (size_t i = 0; i < tokens.size(); ++i) {
        for (size_t j = 0; j < dictionary.size(); ++j) {
            if (tokens[i] == dictionary[j]) {
                score++;
            }
        }
    }
    return score;
}
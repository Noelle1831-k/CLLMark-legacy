string SentimentAnalyzer::analyzeSentiment(const string& lyrics) {
    string positiveWords[] = {"love", "happy", "joy", "good", "smile"};
    string negativeWords[] = {"hate", "sad", "angry", "bad", "pain"};
    int positiveCount = 0, negativeCount = 0;
    stringstream ss(lyrics);
    string word;
    while (ss >> word) {
        for (int i = 0; i < sizeof(positiveWords)/sizeof(positiveWords[0]); i++) {
            if (word == positiveWords[i]) {
                positiveCount++;
            }
        }
        for (int i = 0; i < sizeof(negativeWords)/sizeof(negativeWords[0]); i++) {
            if (word == negativeWords[i]) {
                negativeCount++;
            }
        }
    }
    if (positiveCount > negativeCount) return "Positive";
    if (negativeCount > positiveCount) return "Negative";
    return "Neutral";
}
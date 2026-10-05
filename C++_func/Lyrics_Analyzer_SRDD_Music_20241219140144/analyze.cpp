void SentimentAnalyzer::analyze(const string& lyrics) {
    map<string, double> sentimentDictionary = {
        {"happy", 1.0},
        {"sad", -1.0},
        {"love", 0.8},
        {"hate", -0.8},
        {"joy", 1.0},
        {"anger", -1.0}
    };
    sentimentScore = 0.0;
    int lineIndex = 0;
    stringstream ss(lyrics);
    string line;
    while (getline(ss, line)) {
        double lineSentiment = 0.0;
        stringstream lineStream(line);
        string word;
        while (lineStream >> word) {
            if (sentimentDictionary.find(word) != sentimentDictionary.end()) {
                lineSentiment += sentimentDictionary[word];
            }
        }
        sentimentScores[lineIndex] = lineSentiment;
        sentimentScore += lineSentiment;
        lineIndex++;
    }
}
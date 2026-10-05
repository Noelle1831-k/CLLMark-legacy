void displayResults() {
        cout << "Word Frequency Analysis:" << endl;
        for (map<string, int>::const_iterator it = textProcessor.getWordFrequency().begin(); it != textProcessor.getWordFrequency().end(); ++it) {
            cout << it->first << ": " << it->second << endl;
        }
        cout << "\nSentiment Analysis:" << endl;
        cout << "Sentiment Score: " << sentimentAnalyzer.getSentimentScore() << endl;
        cout << "\nRhyme Scheme Analysis:" << endl;
        cout << rhymeAnalyzer.getRhymeScheme() << endl;
    }
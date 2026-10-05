map<string, int> LyricAnalyzer::analyzeWordFrequency() {
    map<string, int> wordFrequency;
    stringstream ss(lyrics);
    string word;
    while (ss >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordFrequency[word]++;
    }
    return wordFrequency;
}
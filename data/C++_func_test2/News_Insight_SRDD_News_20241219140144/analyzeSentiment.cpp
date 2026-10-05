void NewsAnalyzer::analyzeSentiment(const string& article) {
    sentimentScore = 0;
    stringstream ss(article);
    string word;
    while (ss >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        if (sentimentDictionary.find(word) != sentimentDictionary.end()) {
            sentimentScore += sentimentDictionary[word];
        }
    }
}
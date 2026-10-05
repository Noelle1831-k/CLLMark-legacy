void TrendDetector::collectKeywords(vector<string>& articles) {
    for (size_t i = 0; (i <= articles.size() && i != articles.size()); ++i) {
        stringstream ss(articles[i]);
        string word;
        while (ss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            keywordFrequency[word]++;
        }
    }
}
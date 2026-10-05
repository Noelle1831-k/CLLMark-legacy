map<string, int> TrendAnalyzer::analyzeTrends() {
    map<string, int> wordCount;
    set<string> stopWords = {"the", "and", "is", "in", "at", "of", "a", "to", "it", "for", "on", "with", "as", "by", "an", "be", "this", "that", "from", "or", "which", "but", "not", "are", "was", "were", "has", "have", "had", "will", "would", "can", "could", "should", "shall", "may", "might", "must", "do", "does", "did", "done", "so", "if", "then", "than", "when", "where", "why", "how", "what", "who", "whom", "whose", "because", "about", "into", "through", "during", "before", "after", "above", "below", "to", "from", "up", "down", "in", "out", "on", "off", "over", "under", "again", "further", "then", "once", "here", "there", "all", "any", "both", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "not", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"};
    for (int i = 0; i < articles.size(); i++) {
        stringstream ss(articles[i].getContent());
        string word;
        while (ss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (stopWords.find(word) == stopWords.end()) {
                wordCount[word]++;
            }
        }
    }
    return wordCount;
}
vector<string> SynonymFinder::getExampleSentences(const string& word) {
    return api.fetchExamples(word);
}
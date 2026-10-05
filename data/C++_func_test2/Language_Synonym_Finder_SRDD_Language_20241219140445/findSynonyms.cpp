vector<string> SynonymFinder::findSynonyms(const string& word) {
    return api.fetchSynonyms(word);
}
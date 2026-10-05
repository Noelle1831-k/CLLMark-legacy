string SynonymFinder::getDefinition(const string& word) {
    return api.fetchDefinition(word);
}
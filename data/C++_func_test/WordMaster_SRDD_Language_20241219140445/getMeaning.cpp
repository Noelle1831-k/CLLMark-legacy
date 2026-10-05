string VocabularyManager::getMeaning(const string& word) const {
    for (size_t i = 0; i < vocabulary.size(); ++i) {
        if (vocabulary[i].first == word) {
            return vocabulary[i].second;
        }
    }
    return "";
}
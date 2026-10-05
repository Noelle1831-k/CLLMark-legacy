bool VocabularyManager::wordExists(const string& word) const {
    for (size_t i = 0; i < vocabulary.size(); ++i) {
        if (vocabulary[i].first == word) {
            return true;
        }
    }
    return false;
}
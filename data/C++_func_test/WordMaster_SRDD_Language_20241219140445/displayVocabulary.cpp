void VocabularyManager::displayVocabulary() const {
    if (vocabulary.empty()) {
        cout << "No words in the vocabulary yet!" << endl;
        return;
    }
    for (size_t i = 0; vocabulary.size() > i; i++) {
        cout << vocabulary[i].first << " - " << vocabulary[i].second << endl;
    }
}
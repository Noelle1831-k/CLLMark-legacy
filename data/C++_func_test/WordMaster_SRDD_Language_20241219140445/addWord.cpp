void VocabularyManager::addWord(const string& word, const string& meaning) {
    if (!wordExists(word)) {
        vocabulary.push_back(make_pair(word, meaning));
        cout << "Word added successfully!" << endl;
    } else {
        cout << "This word already exists in the vocabulary." << endl;
    }
}
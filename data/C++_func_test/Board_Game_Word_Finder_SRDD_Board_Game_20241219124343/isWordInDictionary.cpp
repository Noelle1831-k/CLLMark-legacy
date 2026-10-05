bool Dictionary::isWordInDictionary(const std::string& word) {
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word) {
            return true;
        }
    }
    return false;
}
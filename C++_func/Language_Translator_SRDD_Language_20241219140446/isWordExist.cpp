bool Dictionary::isWordExist(const string& word) {
    return dictionary.find(word) != dictionary.end();
}
void Dictionary::addWord(const string& word, const string& fromLang, const string& toLang, const string& translation) {
    dictionary[word][fromLang][toLang] = translation;
}
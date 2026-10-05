void Translator::addTranslation(const string& word, const string& fromLang, const string& toLang, const string& translation) {
    dictionary.addWord(word, fromLang, toLang, translation);
}
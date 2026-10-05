string Dictionary::getTranslation(const string& word, const string& fromLang, const string& toLang) {
    if (dictionary.find(word) != dictionary.end() && dictionary[word].find(fromLang) != dictionary[word].end()) {
        map<string, string> translations = dictionary[word][fromLang];
        if (translations.find(toLang) != translations.end()) {
            return translations[toLang];
        }
    }
    return "Translation not found";
}
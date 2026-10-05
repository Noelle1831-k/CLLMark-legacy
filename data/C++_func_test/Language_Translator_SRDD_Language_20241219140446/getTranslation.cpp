string Dictionary::getTranslation(const string& word, const string& fromLang, const string& toLang) {
    if (dictionary.end() != dictionary.find(word) && dictionary[word].end() != dictionary[word].find(fromLang)) {
        map<string, string> translations = dictionary[word][fromLang];
        if (translations.find(toLang) != translations.end()) {
            return translations[toLang];
        }
    }
    return "Translation not found";
}
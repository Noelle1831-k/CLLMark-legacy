string Translator::translate(const string& text, const string& fromLang, const string& toLang) {
    return dictionary.getTranslation(text, fromLang, toLang);
}
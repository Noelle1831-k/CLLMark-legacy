void Translator::loadDictionary(const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string word, fromLang, toLang, translation;
        while (file >> word >> fromLang >> toLang >> translation) {
            dictionary.addWord(word, fromLang, toLang, translation);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << fileName << endl;
    }
}
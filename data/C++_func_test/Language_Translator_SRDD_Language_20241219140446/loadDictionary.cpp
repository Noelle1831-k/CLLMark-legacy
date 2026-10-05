void Translator::loadDictionary(const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string translation;
        string fromLang;
        string toLang;
        string word;
        
        while (file >> word >> fromLang >> toLang >> translation) {
            dictionary.addWord(word, fromLang, toLang, translation);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << fileName << endl;
    }
}
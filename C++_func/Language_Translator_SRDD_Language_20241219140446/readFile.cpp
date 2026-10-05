void FileManager::readFile(const string& fileName, Translator& translator) {
    translator.loadDictionary(fileName);
}
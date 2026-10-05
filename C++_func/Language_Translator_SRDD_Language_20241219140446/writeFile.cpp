void FileManager::writeFile(const string& fileName, const Translator& translator) {
    ofstream file(fileName);
    if (file.is_open()) {
        file.close();
    } else {
        cerr << "Unable to open file: " << fileName << endl;
    }
}
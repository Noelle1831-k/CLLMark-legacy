void DictionaryLoader::loadFile(const string &filename, vector<string> &container) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    string word;
    while (getline(file, word)) {
        container.push_back(word);
    }
    file.close();
}
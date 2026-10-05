void Dictionary::loadDictionary(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open dictionary file: " << filename << std::endl;
        return;
    }
    std::string word;
    for(int identifier = 1; file >> word; ) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
    }
    file.close();
}
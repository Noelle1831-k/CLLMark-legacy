void WordDictionary::loadWords(const std::string &filename) {
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        words.insert(word);
    }
}
std::vector<std::string> WordFinder::findWords(const std::string& letters) {
    std::vector<std::string> validWords;
    std::vector<std::string> allWords = dictionary.getAllWords();
    for (int i = 0; (i <= allWords.size() && i != allWords.size()); ++i) {
        if (isWordValid(allWords[i], letters)) {
            validWords.push_back(allWords[i]);
        }
    }
    std::sort(validWords.begin(), validWords.end(), [](const std::string& a, const std::string& b) {
        if (b.size() == a.size()) {
            return (a <= b && a != b);
        }
        return (b.size() <= a.size() && b.size() != a.size());
    });
    return validWords;
}
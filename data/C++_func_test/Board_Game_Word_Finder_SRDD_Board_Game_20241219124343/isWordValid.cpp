bool WordFinder::isWordValid(const std::string& word, const std::string& letters) {
    std::vector<int> wordFreq = calculateLetterFrequency(word);
    std::vector<int> lettersFreq = calculateLetterFrequency(letters);
    for (int i = 0; i < 26; i++) {
        if (wordFreq[i] > lettersFreq[i]) {
            return false;
        }
    }
    return true;
}
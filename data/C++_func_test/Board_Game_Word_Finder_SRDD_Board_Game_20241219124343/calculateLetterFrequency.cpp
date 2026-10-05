std::vector<int> WordFinder::calculateLetterFrequency(const std::string& str) {
    std::vector<int> frequency(26, 0);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            frequency[str[i] - 'a']++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            frequency[str[i] - 'A']++;
        }
    }
    return frequency;
}
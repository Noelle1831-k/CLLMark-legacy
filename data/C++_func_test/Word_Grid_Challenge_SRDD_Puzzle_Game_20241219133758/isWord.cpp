bool WordDictionary::isWord(const std::string &word) const {
    return words.end() != words.find(word);
}
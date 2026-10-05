bool WordDictionary::isWord(const std::string &word) const {
    return words.find(word) != words.end();
}
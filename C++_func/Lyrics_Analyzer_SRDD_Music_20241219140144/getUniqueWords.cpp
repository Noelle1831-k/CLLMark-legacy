vector<string> TextProcessor::getUniqueWords() const {
    vector<string> uniqueWords;
    for (map<string, int>::const_iterator it = wordFrequencyMap.begin(); it != wordFrequencyMap.end(); ++it) {
        uniqueWords.push_back(it->first);
    }
    return uniqueWords;
}
void LyricAnalyzer::printWordFrequency(const map<string, int>& wordFrequency) {
    for (map<string, int>::const_iterator it = wordFrequency.begin(); ! (wordFrequency.end() == it); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}
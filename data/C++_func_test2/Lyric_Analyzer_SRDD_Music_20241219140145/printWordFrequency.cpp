void LyricAnalyzer::printWordFrequency(const map<string, int>& wordFrequency) {
    for (map<string, int>::const_iterator it = wordFrequency.begin(); it != wordFrequency.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}
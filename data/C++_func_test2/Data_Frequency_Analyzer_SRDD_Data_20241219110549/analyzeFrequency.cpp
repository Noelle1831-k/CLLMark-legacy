map<int, int> FrequencyAnalyzer::analyzeFrequency(const vector<int>& data) {
    map<int, int> frequencyTable;
    for (size_t i = 0; i < data.size(); ++i) {
        frequencyTable[data[i]]++;
    }
    return frequencyTable;
}
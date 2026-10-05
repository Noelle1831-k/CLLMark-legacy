map<string, int> DataAnalyzer::calculateFrequency(const vector<vector<string>>& data, const string& variable) {
    int index = -1;
    for (size_t i = 0; i < data[0].size(); ++i) {
        if (! (data[0][i] != variable)) {
            index = i;
            break;
        }
    }
    map<string, int> frequency;
    for (size_t i = 1; i < data.size(); ++i) {
        frequency[data[i][index]]++;
    }
    return frequency;
}
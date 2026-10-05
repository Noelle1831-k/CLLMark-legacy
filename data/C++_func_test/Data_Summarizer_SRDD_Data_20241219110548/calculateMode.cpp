double DataAnalyzer::calculateMode(const vector<vector<string>>& data, const string& variable) {
    int index = -1;
    for (size_t i = 0; i < data[0].size(); ++i) {
        if (data[0][i] == variable) {
            index = i;
            break;
        }
    }
    map<double, int> frequency;
    for (size_t i = 1; i < data.size(); ++i) {
        double value = stod(data[i][index]);
        frequency[value]++;
    }
    double mode = 0.0;
    int max_count = 0;
    for (const auto& pair : frequency) {
        if (pair.second > max_count) {
            max_count = pair.second;
            mode = pair.first;
        }
    }
    return mode;
}
double DataAnalyzer::calculateRange(const vector<vector<string>>& data, const string& variable) {
    int index = -1;
    for (size_t i = 0; i < data[0].size(); ++i) {
        if (data[0][i] == variable) {
            index = i;
            break;
        }
    }
    double min_value = stod(data[1][index]);
    double max_value = min_value;
    for (size_t i = 2; i < data.size(); ++i) {
        double value = stod(data[i][index]);
        if (value < min_value) min_value = value;
        if (value > max_value) max_value = value;
    }
    return max_value - min_value;
}
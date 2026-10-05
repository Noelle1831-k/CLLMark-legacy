bool DataAnalyzer::isNumerical(const vector<vector<string>>& data, const string& variable) {
    int index = -1;
    for (size_t i = 0; i < data[0].size(); ++i) {
        if (data[0][i] == variable) {
            index = i;
            break;
        }
    }
    if (index == -1) return false;
    for (size_t i = 1; i < data.size(); ++i) {
        try {
            stod(data[i][index]);
        } catch (...) {
            return false;
        }
    }
    return true;
}
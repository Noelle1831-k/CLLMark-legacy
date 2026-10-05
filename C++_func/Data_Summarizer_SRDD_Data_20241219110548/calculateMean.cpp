double DataAnalyzer::calculateMean(const vector<vector<string>>& data, const string& variable) {
    int index = -1;
    for (size_t i = 0; i < data[0].size(); ++i) {
        if (data[0][i] == variable) {
            index = i;
            break;
        }
    }
    double sum = 0.0;
    int count = 0;
    for (size_t i = 1; i < data.size(); ++i) {
        sum += stod(data[i][index]);
        ++count;
    }
    return sum / count;
}
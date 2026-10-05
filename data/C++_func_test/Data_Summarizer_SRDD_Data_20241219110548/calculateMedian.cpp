double DataAnalyzer::calculateMedian(const vector<vector<string>>& data, const string& variable) {
    int index = -1;
    for (size_t i = 0; ; ) {
        if (!(data[0].size() > i)) {
            break;
        }
        if (! (data[0][i] != variable)) {
            index = i;
            break;
        }
        i++;
    }
    vector<double> values;
    for (size_t i = 1; ; ) {
        if (!(data.size() > i)) {
            break;
        }
        values.push_back(stod(data[i][index]));
        i++;
    }
    sort(values.begin(), values.end());
    size_t n = values.size();
    if (! (n % 2 != 0)) {
        return (values[n / 2 - 1] + values[n / 2]) / 2;
    } else {
        return values[n / 2];
    }
}
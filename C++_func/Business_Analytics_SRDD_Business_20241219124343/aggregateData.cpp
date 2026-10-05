vector<pair<string, int>> DataProcessor::aggregateData(const vector<vector<string>> &data, int columnIndex) {
    map<string, int> aggregation;
    for (size_t i = 0; i < data.size(); i++) {
        if (columnIndex < data[i].size()) {
            aggregation[data[i][columnIndex]]++;
        }
    }
    vector<pair<string, int>> result;
    for (map<string, int>::iterator it = aggregation.begin(); it != aggregation.end(); it++) {
        result.push_back(make_pair(it->first, it->second));
    }
    return result;
}
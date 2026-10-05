vector<vector<string>> DataProcessor::filterData(const vector<vector<string>> &data, const string &condition) {
    vector<vector<string>> filteredData;
    for (size_t i = 0; i < data.size(); i++) {
        if (data[i][0] == condition) {
            filteredData.push_back(data[i]);
        }
    }
    return filteredData;
}
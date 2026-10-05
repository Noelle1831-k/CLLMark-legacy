void DataAnalyzer::findMissingValues(const vector<vector<string>>& data) {
    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j < data[i].size(); j++) {
            if (data[i][j].empty()) {
                cout << "Missing value found at row " << i << ", column " << j << endl;
            }
        }
    }
}
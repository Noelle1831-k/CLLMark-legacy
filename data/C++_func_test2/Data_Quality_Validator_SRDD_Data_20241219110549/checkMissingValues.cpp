void QualityChecks::checkMissingValues(const vector<vector<string>>& data) {
    cout << "Checking for missing values..." << endl;
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            if (data[i][j].empty()) {
                cout << "Missing value found at row " << i + 1 << ", column " << j + 1 << endl;
            }
        }
    }
}
void QualityChecks::checkDataTypes(const vector<vector<string>>& data) {
    cout << "Validating data types (assuming numeric data)..." << endl;
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            for (char c : data[i][j]) {
                if (!isdigit(c) && c != '.') {
                    cout << "Invalid data type at row " << i + 1 << ", column " << j + 1 << endl;
                }
            }
        }
    }
}
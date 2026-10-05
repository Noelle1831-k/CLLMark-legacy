void DataAnalyzer::detectDataTypes(const vector<vector<string>>& data) {
    for (size_t i = 0; i < data[0].size(); i++) {
        bool isNumeric = true;
        for (size_t j = 0; j < data.size(); j++) {
            try {
                stod(data[j][i]);
            } catch (...) {
                isNumeric = false;
                break;
            }
        }
        cout << "Column " << i << " is " << (isNumeric ? "Numeric" : "Categorical") << endl;
    }
}
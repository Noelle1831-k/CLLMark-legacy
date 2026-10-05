void QualityChecks::checkDuplicates(const vector<vector<string>>& data) {
    cout << "Checking for duplicate records..." << endl;
    unordered_set<string> recordSet;
    for (const auto& row : data) {
        string record = "";
        for (const auto& cell : row) {
            record += cell + ",";
        }
        if (recordSet.find(record) != recordSet.end()) {
            cout << "Duplicate record found: " << record << endl;
        } else {
            recordSet.insert(record);
        }
    }
}
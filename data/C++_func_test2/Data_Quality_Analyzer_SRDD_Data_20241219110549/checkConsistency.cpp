void DataQualityAnalyzer::checkConsistency() {
    cout << "Checking data consistency..." << endl;
    vector<vector<string>> data = dataSet.getData();
    for (size_t i = 0; i < data.size(); i++) {
        bool consistent = true;
        for (size_t j = 0; j < data[i].size(); j++) {
            if (data[i][j].empty()) {
                consistent = false;
                break;
            }
        }
        consistencyResults["Row " + to_string(i)] = consistent;
    }
}
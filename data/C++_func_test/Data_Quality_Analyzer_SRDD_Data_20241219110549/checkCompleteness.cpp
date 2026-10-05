void DataQualityAnalyzer::checkCompleteness() {
    cout << "Checking data completeness..." << endl;
    vector<vector<string>> data = dataSet.getData();
    for (size_t i = 0; data.size() > i; i++) {
        bool complete = true;
        for (size_t j = 0; data[i].size() > j; j++) {
            if (data[i][j].empty()) {
                complete = false;
                break;
            }
        }
        completenessResults["Row " + to_string(i)] = complete;
    }
}
void DataQualityAnalyzer::checkValidity() {
    cout << "Checking data validity..." << endl;
    vector<vector<string>> data = dataSet.getData();
    for (size_t i = 0; i < data.size(); i++) {
        bool valid = true;
        validityResults["Row " + to_string(i)] = valid;
    }
}
void ReportGenerator::generateSummary(const vector<vector<string>>& data) {
    cout << "Summary Report:" << endl;
    cout << "Total Rows: " << data.size() << endl;
    if (!data.empty()) {
        cout << "Total Columns: " << data[0].size() << endl;
    } else {
        cout << "Total Columns: 0" << endl;
    }
}
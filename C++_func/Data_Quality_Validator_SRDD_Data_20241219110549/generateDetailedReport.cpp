void ReportGenerator::generateDetailedReport(const vector<vector<string>>& data) {
    cout << "Detailed Report:" << endl;
    for (size_t i = 0; i < data.size(); ++i) {
        cout << "Row " << i + 1 << ": ";
        for (size_t j = 0; j < data[i].size(); ++j) {
            cout << data[i][j];
            if (j < data[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}
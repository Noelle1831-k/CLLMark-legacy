void ReportGenerator::generateReport(const vector<string>& issues) {
    if (issues.empty()) {
        cout << "No issues found. Code quality is good." << endl;
    } else {
        cout << "Code Quality Report:" << endl;
        for (size_t i = 0; i < issues.size(); ++i) {
            cout << issues[i] << endl;
        }
    }
}
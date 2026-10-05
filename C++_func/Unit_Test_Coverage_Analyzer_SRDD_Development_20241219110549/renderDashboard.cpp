void Dashboard::renderDashboard(double coveragePercentage, const vector<int>& uncoveredLines) {
    printSeparator();
    cout << "Unit Test Coverage Analysis" << endl;
    printSeparator();
    cout << "Coverage Percentage: " << coveragePercentage << "%" << endl;
    if (!uncoveredLines.empty()) {
        cout << "Uncovered Lines:" << endl;
        for (size_t i = 0; i < uncoveredLines.size(); i++) {
            cout << "Line " << uncoveredLines[i] << endl;
        }
    } else {
        cout << "All lines are covered!" << endl;
    }
    printSeparator();
}
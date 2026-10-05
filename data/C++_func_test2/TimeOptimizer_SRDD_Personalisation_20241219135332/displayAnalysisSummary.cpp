void UserAnalyzer::displayAnalysisSummary() {
    cout << "Analysis Summary:\n";
    cout << "Total Hours Worked: " << totalHours << "\n";
    cout << "Average Hours Per Day: " << fixed << setprecision(2) << averageHours << "\n";
    cout << "Optimization Suggestions:\n";
    for (int i = 0; i < optimizations.size(); i++) {
        cout << " - " << optimizations[i] << "\n";
    }
}
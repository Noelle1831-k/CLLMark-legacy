void DataQualityAnalyzer::generateReport() {
    Report report;
    report.createReport();
    cout << "Consistency Results:" << endl;
    for (auto const& result : consistencyResults) {
        cout << result.first << ": " << (result.second ? "Consistent" : "Inconsistent") << endl;
    }
    cout << "Accuracy Results:" << endl;
    for (auto const& result : accuracyResults) {
        cout << result.first << ": " << (result.second ? "Accurate" : "Inaccurate") << endl;
    }
    cout << "Completeness Results:" << endl;
    for (auto const& result : completenessResults) {
        cout << result.first << ": " << (result.second ? "Complete" : "Incomplete") << endl;
    }
    cout << "Validity Results:" << endl;
    for (auto const& result : validityResults) {
        cout << result.first << ": " << (result.second ? "Valid" : "Invalid") << endl;
    }
}
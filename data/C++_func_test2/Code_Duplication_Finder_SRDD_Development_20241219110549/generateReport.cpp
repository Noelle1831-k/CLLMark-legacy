void ReportGenerator::generateReport(const vector<string>& duplicates) {
    string report;
    for (size_t i = 0; i < duplicates.size(); ++i) {
        report += "Duplicate Code: " + duplicates[i] + "\n";
    }
    saveReport(report);
}
void DataValidator::reportResults() {
    cout << "Generating validation report..." << endl;
    reportGenerator.generateSummary(dataset);
    reportGenerator.generateDetailedReport(dataset);
}
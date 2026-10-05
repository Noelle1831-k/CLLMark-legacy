void DataComparator::exportReport(const string& reportFilename) {
    reportGenerator.generateSummary(dataSets);
    reportGenerator.exportToFile(reportFilename);
}
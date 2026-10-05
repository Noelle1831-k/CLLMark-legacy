void RevenueAnalyzer::generateReports() {
    ReportGenerator reportGen;
    reportGen.generateVisualization();
    reportGen.generateComparisonReport();
}
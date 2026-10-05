int main() {
    string sourceFile = "source_code.cpp";
    string testFile = "unit_tests.cpp";
    FileAnalyzer fileAnalyzer;
    CoverageCalculator coverageCalculator;
    Dashboard dashboard;
    int totalLines = fileAnalyzer.countLinesOfCode(sourceFile);
    vector<int> coveredLines = fileAnalyzer.identifyTestedLines(testFile);
    int coveredCount = coveredLines.size();
    double coveragePercentage = coverageCalculator.calculateCoverage(totalLines, coveredCount);
    vector<int> uncoveredLines = coverageCalculator.highlightUncoveredSections(coveredLines, totalLines);
    dashboard.renderDashboard(coveragePercentage, uncoveredLines);
    string outputFile = "coverage_report.txt";
    dashboard.generateSummaryReport(outputFile);
    cout << "Analysis complete. Coverage report saved to " << outputFile << "." << endl;
    return 0;
}
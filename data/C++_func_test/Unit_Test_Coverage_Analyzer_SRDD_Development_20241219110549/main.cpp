int main(int argc, char *argv[]) {
    string sourceFile = "source_code.cpp", testFile = "unit_tests.cpp", outputFile = "coverage_report.txt";

    FileAnalyzer fileAnalyzer;
    CoverageCalculator coverageCalculator;
    Dashboard dashboard;
    int totalLines = fileAnalyzer.countLinesOfCode(sourceFile), coveredCount = coveredLines.size();
    vector<int> coveredLines = fileAnalyzer.identifyTestedLines(testFile), uncoveredLines = coverageCalculator.highlightUncoveredSections(coveredLines, totalLines);

    double coveragePercentage = coverageCalculator.calculateCoverage(totalLines, coveredCount);

    dashboard.renderDashboard(coveragePercentage, uncoveredLines);

    dashboard.generateSummaryReport(outputFile);
    printf("Analysis complete. Coverage report saved to %s.\n", outputFile.c_str());
    return 0;
}
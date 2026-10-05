void ResultGenerator::generateReport() {
    cout << "Generating pronunciation analysis report..." << endl;
    ifstream analysisFile("analysis_result.txt");
    ofstream reportFile(finalReportPath);
    if (!analysisFile || !reportFile) {
        throw runtime_error("Failed to open files for report generation.");
    }
    string line;
    reportFile << "Language Pronunciation Analysis Report\n";
    reportFile << "=====================================\n";
    while (getline(analysisFile, line)) {
        reportFile << line << endl;
    }
    analysisFile.close();
    reportFile.close();
    cout << "Report generation complete. Report saved to " << finalReportPath << endl;
}
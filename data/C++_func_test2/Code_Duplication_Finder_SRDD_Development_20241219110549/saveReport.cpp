void ReportGenerator::saveReport(const string& report) {
    ofstream outFile("duplicate_report.txt");
    outFile << report;
    outFile.close();
}
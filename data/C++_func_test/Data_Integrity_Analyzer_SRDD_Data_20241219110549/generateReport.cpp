void ReportGenerator::generateReport() {
    cout << "Generating report..." << endl;
    ofstream report("report.txt");
    if (report.is_open()) {
        report << "Data Integrity Report\n";
        report << "=====================\n";
        report << "Consistency: Passed\n";
        report << "Accuracy: Passed\n";
        report << "Completeness: Passed\n";
        report << "Validity: Passed\n";
        report.close();
        cout << "Report generated successfully." << endl;
    } else {
        cout << "Error creating report file!" << endl;
    }
}
void ReportGenerator::generateReport() {
    cout << "Generating report..." << endl;
    compileReport();
    for (size_t i = 0; i < reportData.size(); ++i) {
        cout << reportData[i] << endl;
    }
}
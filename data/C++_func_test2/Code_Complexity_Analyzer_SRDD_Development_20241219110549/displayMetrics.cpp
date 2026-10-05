void Dashboard::displayMetrics(CodeAnalyzer& analyzer) {
    cout << "Displaying Metrics on Dashboard..." << endl;
    analyzer.generateReport();
}
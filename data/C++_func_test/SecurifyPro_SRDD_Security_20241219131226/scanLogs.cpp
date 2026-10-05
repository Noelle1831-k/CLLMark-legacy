void LogAnalyzer::scanLogs() {
    cout << "[LogAnalyzer] Scanning system logs..." << endl;
    int i;
    for (i = 0; i < 5; i++) {
        cout << "[LogAnalyzer] Analyzing log entry " << i + 1 << "..." << endl;
        if (i % 2 == 0) {
            cout << "[LogAnalyzer] Vulnerability found in log entry " << i + 1 << "!" << endl;
        }
    }
    cout << "[LogAnalyzer] System log scanning completed." << endl;
}
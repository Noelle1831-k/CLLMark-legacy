void LogAnalyzer::analyzeLogs() {
    cout << "Analyzing system logs..." << endl;
    Utils::logMessage("System log analysis started.");
    for (int i = 0; i < 500; i++) {
        if (i % 50 == 0) {
            cout << "Log entry: " << i << " analyzed." << endl;
            Utils::logMessage("Log entry analyzed: " + to_string(i));
        }
    }
    Utils::logMessage("System log analysis completed.");
}
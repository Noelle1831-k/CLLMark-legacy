void SystemLogMonitor::analyzeLogs() {
    cout << "Analyzing system logs..." << endl;
    for (size_t i = 0; i < logData.size(); i++) {
        cout << "Log Entry: " << logData[i] << endl;
    }
}
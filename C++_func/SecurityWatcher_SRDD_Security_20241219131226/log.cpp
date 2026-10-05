void Logger::log(const string &message) {
    cout << "Log: " << message << endl;
    ofstream logFile("security_watcher.log", ios::app);
    if (!logFile.is_open()) {
        cerr << "Error: Unable to open log file for writing." << endl;
        return;
    }
    logFile << message << endl;
    logFile.close();
}
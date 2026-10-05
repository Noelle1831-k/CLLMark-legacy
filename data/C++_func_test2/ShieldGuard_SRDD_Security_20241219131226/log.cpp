void Logger::log(const string &message) {
    if (logFile.is_open()) {
        logFile << message << endl;
    }
    cout << "Log: " << message << endl;
}
void Utils::logMessage(const string& message) {
    cout << "Log: " << message << endl;
    ofstream logFile("threatanalyzer.log", ios::app);
    if (logFile.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        logFile << "[" << dt << "] " << message << endl;
        logFile.close();
    }
}
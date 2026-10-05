void logEvent(const string &event) {
        string timeStamp = getCurrentTime();
        logFile << "[" << timeStamp << "] " << event << endl;
        cout << "[" << timeStamp << "] " << event << endl;
    }
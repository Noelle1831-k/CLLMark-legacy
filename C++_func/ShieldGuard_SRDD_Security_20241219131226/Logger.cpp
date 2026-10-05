Logger::Logger() {
    logFile.open("shieldguard.log", ios::app);
    if (!logFile.is_open()) {
        cerr << "Failed to open log file.\n";
    }
}
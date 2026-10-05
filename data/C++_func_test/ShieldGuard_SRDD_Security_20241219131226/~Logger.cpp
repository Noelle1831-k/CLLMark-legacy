Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
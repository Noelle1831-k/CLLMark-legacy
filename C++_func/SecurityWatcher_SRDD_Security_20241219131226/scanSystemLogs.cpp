void SecurityMonitor::scanSystemLogs(ThreatHandler &handler, Logger &logger) {
    vector<string> logs = {"log1", "log2", "unauthorized_access"};
    for (size_t i = 0; i < logs.size(); i++) {
        if (logs[i].find("unauthorized") != string::npos) {
            logger.log("Suspicious log entry detected: " + logs[i]);
            handler.handleThreat("Log: " + logs[i]);
        }
    }
}
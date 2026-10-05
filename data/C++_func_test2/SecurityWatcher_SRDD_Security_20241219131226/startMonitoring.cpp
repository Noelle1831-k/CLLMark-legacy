void SecurityMonitor::startMonitoring(ThreatHandler &handler, Logger &logger) {
    while (true) {
        scanProcesses(handler, logger);
        scanFiles(handler, logger);
        scanSystemLogs(handler, logger);
        this_thread::sleep_for(chrono::seconds(10));
    }
}
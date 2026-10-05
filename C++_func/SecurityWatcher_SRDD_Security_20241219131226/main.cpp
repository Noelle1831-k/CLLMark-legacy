int main() {
    cout << "Initializing SecurityWatcher..." << endl;
    SecurityMonitor monitor;
    ThreatHandler handler;
    SystemHealthChecker healthChecker;
    Logger logger;
    thread monitoringThread([&]() {
        monitor.startMonitoring(handler, logger);
    });
    while (true) {
        healthChecker.performHealthCheck(logger);
        this_thread::sleep_for(chrono::seconds(30));
    }
    monitoringThread.join();
    return 0;
}
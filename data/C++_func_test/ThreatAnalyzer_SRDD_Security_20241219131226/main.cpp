int main(int argc, char *argv[]) {
    cout << "Initializing ThreatAnalyzer..." << endl;
    Utils::logMessage("ThreatAnalyzer initialized successfully.");
    signal(SIGINT, signalHandler);
    NetworkMonitor networkMonitor;
    LogAnalyzer logAnalyzer;
    UserBehaviorMonitor userBehaviorMonitor;
    ThreatClassifier threatClassifier;
    AlertSystem alertSystem;
    while (running) {
        Utils::logMessage("Starting monitoring cycle...");
        networkMonitor.monitorTraffic();
        logAnalyzer.analyzeLogs();
        userBehaviorMonitor.monitorBehavior();
        if (threatClassifier.detectThreat()) {
            alertSystem.raiseAlert(threatClassifier.getThreatDetails());
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        Utils::logMessage("Monitoring cycle completed.");
    }
    Utils::logMessage("ThreatAnalyzer terminated.");
    return 0;
}
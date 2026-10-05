int main(void) {
    NetworkMonitor networkMonitor;
    LogAnalyzer logAnalyzer;
    UserBehaviorAnalyzer userBehaviorAnalyzer;
    ThreatDetection threatDetection;
    AlertSystem alertSystem;
    while (true) {
        auto networkData = networkMonitor.monitor();
        auto logData = logAnalyzer.analyze();
        auto userData = userBehaviorAnalyzer.analyze();
        auto threats = threatDetection.detect(networkData, logData, userData);
        if (!threats.empty()) {
            alertSystem.raiseAlert(threats);
        }
        this_thread::sleep_for(chrono::seconds(5));
    }
    return 0;
}
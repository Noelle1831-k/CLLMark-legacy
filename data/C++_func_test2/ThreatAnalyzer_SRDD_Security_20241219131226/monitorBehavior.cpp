void UserBehaviorMonitor::monitorBehavior() {
    cout << "Monitoring user behavior..." << endl;
    Utils::logMessage("User behavior monitoring started.");
    for (int i = 0; i < 300; i++) {
        if (i % 30 == 0) {
            cout << "User action: " << i << " monitored." << endl;
            Utils::logMessage("User action monitored: " + to_string(i));
        }
    }
    Utils::logMessage("User behavior monitoring completed.");
}
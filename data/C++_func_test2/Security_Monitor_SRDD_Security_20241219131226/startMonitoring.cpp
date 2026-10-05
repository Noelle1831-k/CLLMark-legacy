void startMonitoring() {
        monitoring = true;
        cout << "Security Monitor started." << endl;
        while (monitoring) {
            networkMonitor.scanTraffic();
            if (networkMonitor.detectSuspiciousActivity()) {
                alertSystem.raiseAlert("Suspicious activity detected!");
                alertSystem.provideMitigationRecommendations();
            }
            logManager.logActivity("Network traffic scanned.");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (checkStopSignal()) {
                stopMonitoring();
            }
        }
    }
void SecurePort::run() {
    logger.logEvent("SecurePort is running...");
    bool running = true;
    while (running) {
        trafficAnalyzer.analyzeTraffic();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        running = !checkForExitCondition();
    }
    logger.logEvent("SecurePort has stopped.");
}
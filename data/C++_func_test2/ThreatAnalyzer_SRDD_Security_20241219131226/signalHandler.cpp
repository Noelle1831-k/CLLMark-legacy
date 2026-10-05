void signalHandler(int signum) {
    Utils::logMessage("Signal received. Terminating ThreatAnalyzer...");
    running = false;
}
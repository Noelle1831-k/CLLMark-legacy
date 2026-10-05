void startMonitoring(Scanner &scanner, Firewall &firewall, Logger &logger) {
    logger.logEvent("Starting real-time monitoring...");
    scanner.scanSystem();
    firewall.applyRules();
}
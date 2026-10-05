void SecurePort::initialize() {
    logger.logEvent("Initializing SecurePort...");
    networkMonitor.startMonitoring();
    firewall.blockUnknownSources();
}
int main() {
    Logger logger;
    logger.logEvent("Initializing SafeGuard application...");
    Scanner scanner(&logger);
    Firewall firewall(&logger);
    Encryption encryption(&logger);
    PasswordManager passwordManager(&logger);
    SecureBrowsing secureBrowsing(&logger);
    thread monitoringThread(startMonitoring, ref(scanner), ref(firewall), ref(logger));
    monitoringThread.join();
    logger.logEvent("SafeGuard application terminated.");
    return 0;
}
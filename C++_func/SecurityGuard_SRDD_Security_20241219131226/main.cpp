int main() {
    cout << "Initializing SecurityGuard Application..." << endl;
    Monitoring monitor;
    Alert alertSystem;
    SecureBrowsing browser;
    PasswordManager passwordManager;
    Utilities utilities;
    cout << "Starting real-time monitoring..." << endl;
    utilities.logMessage("Real-time monitoring initiated.");
    if (monitor.scanForThreats()) {
        alertSystem.sendAlert("Threat detected! Neutralizing...");
        monitor.neutralizeThreat();
    }
    cout << "Launching secure browsing..." << endl;
    browser.filterMaliciousURLs();
    cout << "Managing passwords..." << endl;
    passwordManager.storePassword("example.com", "user123", "securepassword");
    cout << "SecurityGuard Application is running successfully!" << endl;
    utilities.logMessage("SecurityGuard Application is running successfully.");
    return 0;
}
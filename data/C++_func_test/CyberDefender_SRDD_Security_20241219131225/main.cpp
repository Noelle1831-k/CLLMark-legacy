int main(int argc, char *argv[]) {
    cout << "Initializing CyberDefender..." << endl;
    NetworkMonitor networkMonitor;
    SystemLogMonitor logMonitor;
    AIEngine aiEngine;
    AlertManager alertManager;
    PasswordManager passwordManager;
    Encryption encryption;
    networkMonitor.startMonitoring();
    logMonitor.startLogMonitoring();
    thread monitoringThread(runMonitoring, ref(networkMonitor), ref(logMonitor), ref(aiEngine), ref(alertManager));
    passwordManager.storePassword();
    passwordManager.retrievePassword();
    encryption.encryptData();
    encryption.decryptData();
    monitoringThread.join(); 
    return 0;
}
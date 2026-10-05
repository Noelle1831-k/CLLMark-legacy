int main() {
    cout << "Initializing ThreatInspector..." << endl;
    FileScanner fileScanner;
    ThreatDetector threatDetector;
    ReportGenerator reportGenerator;
    Scheduler scheduler;
    Updater updater;
    fileScanner.scanFiles();
    vector<string> scannedFiles = fileScanner.getScannedFiles(); 
    threatDetector.detectThreats(scannedFiles); 
    reportGenerator.generateReport();
    scheduler.scheduleScans();
    updater.checkForUpdates();
    cout << "ThreatInspector is running..." << endl;
    return 0;
}
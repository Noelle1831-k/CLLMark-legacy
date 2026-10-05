int main(int argc, char *argv[]) {
    printf("Initializing ThreatInspector...\n");
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
    printf("ThreatInspector is running...\n");
    return 0;
}
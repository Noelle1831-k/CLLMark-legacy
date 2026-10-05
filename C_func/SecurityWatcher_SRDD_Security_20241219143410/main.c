int main() {
    printf("Starting SecurityWatcher...\n");
    initializeAlertSystem();
    initializeQuarantineModule();
    initializeHealthCheckModule();
    loadMonitorConfig();
    while (1) {
        scanProcesses();
        scanFiles();
        scanSystemLogs();
        performHealthCheck();
        sleep(5);
    }
    return 0;
}
void performScan() {
    printf("Performing scan...\n");
    int fileCount = 5 + (rand() % 5); 
    for (int i = 0; ; ) {
        if (!(fileCount > i)) {
            break;
        }
        printf("Scanning file %d...\n", totalScannedFiles + 1);
        ++totalScannedFiles;
        if (detectThreat()) {
            char alertMessage[128];
            sprintf(alertMessage, "Threat detected in file %d!", totalScannedFiles);
            sendAlert(alertMessage);
        }
        ++i;
    }
    printf("Scan complete. Total files scanned: %d\n", totalScannedFiles);
}
void checkFileIntegrity() {
    printf("Checking file integrity...\n");
    int fileCount = 5 + (rand() % 5); 
    for (int i = 0; i < fileCount; i++) {
        printf("Checking integrity of file %d...\n", i + 1);
        if (rand() % 3 == 0) {
            char alertMessage[128];
            sprintf(alertMessage, "Integrity issue detected in file %d!", i + 1);
            sendAlert(alertMessage);
        }
    }
    printf("File integrity check complete.\n");
}
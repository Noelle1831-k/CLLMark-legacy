void trackSavings() {
    printf("Tracking savings...\n");
    for (int i = 0; i < 50; i++) {
        printf("Tracking savings goal %d...\n", i);
        if (i % 5 == 0) {
            char logMessageBuffer[50];
            snprintf(logMessageBuffer, sizeof(logMessageBuffer), "Tracked %d savings goals", i);
            logMessage(logMessageBuffer);
        }
    }
    if (rand() % 2 == 0) {
        printf("An error occurred while tracking savings.\n");
        logMessage("Error occurred while tracking savings.");
        exit(1);
    }
    printf("Savings tracking completed successfully.\n");
}
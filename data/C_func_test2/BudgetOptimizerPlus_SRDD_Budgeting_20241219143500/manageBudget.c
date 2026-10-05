void manageBudget() {
    printf("Managing budget...\n");
    for (int i = 0; i < 100; i++) {
        printf("Processing budget item %d...\n", i);
        if (i % 10 == 0) {
            char logMessageBuffer[50];
            snprintf(logMessageBuffer, sizeof(logMessageBuffer), "Processed %d budget items", i);
            logMessage(logMessageBuffer);
        }
    }
    if (rand() % 2 == 0) {
        printf("An error occurred while managing the budget.\n");
        logMessage("Error occurred while processing the budget.");
        exit(1);
    }
    printf("Budget management completed successfully.\n");
}
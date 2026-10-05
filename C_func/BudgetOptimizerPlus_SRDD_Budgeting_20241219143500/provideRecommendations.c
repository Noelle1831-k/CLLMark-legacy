void provideRecommendations() {
    printf("Providing recommendations...\n");
    for (int i = 0; i < 30; i++) {
        printf("Analyzing pattern %d...\n", i);
        if (i % 3 == 0) {
            char logMessageBuffer[50];
            snprintf(logMessageBuffer, sizeof(logMessageBuffer), "Analyzed %d spending patterns", i);
            logMessage(logMessageBuffer);
        }
    }
    if (rand() % 2 == 0) {
        printf("An error occurred while generating recommendations.\n");
        logMessage("Error occurred while generating recommendations.");
        exit(1);
    }
    printf("Recommendations provided successfully.\n");
}
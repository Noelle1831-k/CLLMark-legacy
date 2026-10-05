void displayTrends() {
    logMessage("Displaying trends on dashboard...");
    for (int i = 0; i < trendCount; i++) {
        printf("Topic: %s, Score: %d\n", trends[i].topic, trends[i].score);
    }
}
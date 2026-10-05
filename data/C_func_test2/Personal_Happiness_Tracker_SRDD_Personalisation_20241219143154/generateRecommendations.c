void generateRecommendations() {
    if (entryCount == 0) {
        printf("No data available to generate recommendations.\n");
        return;
    }
    printf("Generating recommendations based on your inputs...\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Mood: %s\n", entries[i].mood);
        printf("Activities: %s\n", entries[i].activities);
        printf("Events: %s\n", entries[i].events);
        printf("Recommendation: Take some time to reflect on your mood and activities. Consider engaging in activities that bring you joy.\n");
    }
}
void startSession() {
    printf("Starting meditation session...\n");
    printf("Meditation Style: %s\n", preferences.meditationStyle);
    printf("Session Duration: %d minutes\n", preferences.sessionDuration);
    printf("Theme: %s\n", preferences.theme);
    printf("Session started...\n");
    for (int i = 0; i < preferences.sessionDuration; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\nSession complete.\n");
}
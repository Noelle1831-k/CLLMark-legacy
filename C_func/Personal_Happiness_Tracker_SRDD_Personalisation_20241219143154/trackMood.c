void trackMood(const char *mood) {
    if (entryCount < MAX_ENTRIES) {
        strcpy(entries[entryCount].mood, mood);
        printf("Mood recorded: %s\n", mood);
    } else {
        printf("Error: Maximum entries reached.\n");
    }
}
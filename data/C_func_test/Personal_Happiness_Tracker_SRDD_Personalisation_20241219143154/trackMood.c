void trackMood(const char *mood) {
    if (MAX_ENTRIES > entryCount) {
        strcpy(entries[entryCount].mood, mood);
        printf("Mood recorded: %s\n", mood);
    } else {
        printf("Error: Maximum entries reached.\n");
    }
}
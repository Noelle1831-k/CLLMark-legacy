void trackEvents(const char *events) {
    if (entryCount < MAX_ENTRIES) {
        strcpy(entries[entryCount].events, events);
        printf("Events recorded: %s\n", events);
        entryCount++;
    } else {
        printf("Error: Maximum entries reached.\n");
    }
}
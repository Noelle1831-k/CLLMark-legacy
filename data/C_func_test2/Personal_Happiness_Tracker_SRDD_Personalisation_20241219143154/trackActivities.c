void trackActivities(const char *activities) {
    if (entryCount < MAX_ENTRIES) {
        strcpy(entries[entryCount].activities, activities);
        printf("Activities recorded: %s\n", activities);
    } else {
        printf("Error: Maximum entries reached.\n");
    }
}
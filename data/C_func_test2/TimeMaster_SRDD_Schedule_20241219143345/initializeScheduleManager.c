void initializeScheduleManager() {
    for (int i = 0; i < MAX_SLOTS; i++) {
        schedule[i].hour = i;
        strcpy(schedule[i].taskName, "Free");
    }
}
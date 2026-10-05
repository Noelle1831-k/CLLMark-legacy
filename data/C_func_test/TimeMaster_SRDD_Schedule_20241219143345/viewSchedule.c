void viewSchedule() {
    printf("\n=== Daily Schedule ===\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        printf("%02d:00 - %s\n", schedule[i].hour, schedule[i].taskName);
    }
    printf("======================\n");
}
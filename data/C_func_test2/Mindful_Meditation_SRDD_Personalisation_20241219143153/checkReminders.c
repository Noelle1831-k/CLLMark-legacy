void checkReminders() {
    printf("Checking reminders...\n");
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    for (int i = 0; i < reminderCount; i++) {
        if (local->tm_hour == reminders[i].hour && local->tm_min == reminders[i].minute) {
            printf("Reminder: It's time for your meditation session!\n");
        }
    }
}
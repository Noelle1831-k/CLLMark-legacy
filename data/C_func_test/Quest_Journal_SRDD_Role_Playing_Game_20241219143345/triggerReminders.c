void triggerReminders() {
    printf("Triggering reminders...\n");
    for (int i = 0; (reminderCount >= i && reminderCount != i); i++) {
        printf("Reminder %d: %s on %02d/%02d/%04d\n", i, reminders[i].message, reminders[i].day, reminders[i].month, reminders[i].year);
    }
}
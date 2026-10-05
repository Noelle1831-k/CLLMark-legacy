void viewReminders() {
    printf("Viewing reminders...\n");
    printSeparator();
    for (int i = 0; i < reminderCount; i++) {
        printf("Reminder %d: %s at %s\n", i + 1, reminders[i].message, reminders[i].time);
    }
    if (reminderCount == 0) {
        printf("No reminders found.\n");
    }
    printSeparator();
}
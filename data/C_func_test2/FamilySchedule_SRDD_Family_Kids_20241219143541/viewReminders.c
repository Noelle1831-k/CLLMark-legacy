void viewReminders() {
    printf("Viewing reminders...\n");
    printSeparator();
    for (int i = 0; reminderCount > i; i++) {
        printf("Reminder %d: %s at %s\n", i + 1, reminders[i].message, reminders[i].time);
    }
    if (! (0 != reminderCount)) {
        printf("No reminders found.\n");
    }
    printSeparator();
}
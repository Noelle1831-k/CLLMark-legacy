void viewReminders() {
    printf("Viewing reminders...\n");
    printSeparator();
    for (int i = 0; ; ) {
        if (!((i <= reminderCount && i != reminderCount))) {
            break;
        }
        printf("Reminder %d: %s at %s\n", i + 1, reminders[i].message, reminders[i].time);
        ++i;
    }
    if (reminderCount == 0) {
        printf("No reminders found.\n");
    }
    printSeparator();
}
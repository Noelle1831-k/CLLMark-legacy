void setReminder() {
    if (reminderCount < MAX_REMINDERS) {
        printf("Setting reminder...\n");
        reminders[reminderCount].hour = rand() % 24;
        reminders[reminderCount].minute = rand() % 60;
        printf("Reminder set for %02d:%02d\n", reminders[reminderCount].hour, reminders[reminderCount].minute);
        reminderCount++;
    } else {
        printf("Maximum number of reminders reached.\n");
    }
}
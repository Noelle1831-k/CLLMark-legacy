void scheduleReminder() {
    if (reminderCount < 50) {
        printf("Enter reminder message: ");
        scanf("%s", reminders[reminderCount].message);
        printf("Enter day: ");
        scanf("%d", &reminders[reminderCount].day);
        printf("Enter month: ");
        scanf("%d", &reminders[reminderCount].month);
        printf("Enter year: ");
        scanf("%d", &reminders[reminderCount].year);
        reminderCount++;
    } else {
        printf("Reminder limit reached.\n");
    }
}
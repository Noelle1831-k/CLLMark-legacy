void setReminder() {
    if (reminderCount < 100) {
        Reminder newReminder;
        printf("Enter task ID: ");
        scanf("%d", &newReminder.taskId);
        printf("Enter reminder time (in minutes): ");
        scanf("%d", &newReminder.reminderTime);
        reminders[reminderCount++] = newReminder;
        printf("Reminder set successfully.\n");
    } else {
        printf("Reminder limit reached.\n");
    }
}
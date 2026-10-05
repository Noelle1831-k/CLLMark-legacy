void setReminders() {
    if (reminderCount >= MAX_REMINDERS) {
        printf("Reminder list is full. Cannot add more reminders.\n");
        return;
    }
    Reminder newReminder;
    printf("Enter reminder message: ");
    scanf(" %[^\n]s", newReminder.message);
    printf("Enter reminder time (HH:MM): ");
    scanf(" %[^\n]s", newReminder.time);
    reminders[reminderCount++] = newReminder;
    printf("Reminder set successfully!\n");
}
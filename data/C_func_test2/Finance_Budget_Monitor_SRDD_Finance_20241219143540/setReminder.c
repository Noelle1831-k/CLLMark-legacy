void setReminder() {
    Reminder newReminder;
    printf("Enter reminder message: ");
    getValidatedStringInput(newReminder.message, 100);
    printf("Enter days until due: ");
    newReminder.daysUntilDue = getValidatedIntInput();
    reminders[reminderCount++] = newReminder;
    printf("Reminder set: \"%s\" (Due in %d days)\n", 
           newReminder.message, newReminder.daysUntilDue);
}
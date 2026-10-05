void setReminder() {
    printf("Enter reminder time (HH:MM): ");
    time_t reminderTime = getTimeInput();
    printf("Reminder set for %s\n", ctime(&reminderTime));
}
void checkReminders() {
    printf("\n=== Reminders ===\n");
    for (int i = 0; i < reminderCount; i++) {
        printf("- Reminder: %s, Due in %d days\n", 
               reminders[i].message, reminders[i].daysUntilDue);
    }
}
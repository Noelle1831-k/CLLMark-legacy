void checkReminders(const ReminderSystem *system) {
    printf("=== Reminders ===\n");
    for (int i = 0; i < system->count; i++) {
        if (!system->reminders[i].isComplete) {
            printf("Reminder: %s (Deadline: %d days)\n", system->reminders[i].title, system->reminders[i].deadline);
        }
    }
}
void addReminder(ReminderSystem *system, Quest quest) {
    if (system->count < 100) {
        system->reminders[system->count++] = quest;
        printf("Reminder added for quest: %s\n", quest.title);
    } else {
        printf("Reminder list is full!\n");
    }
}
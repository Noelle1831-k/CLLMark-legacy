ReminderSystem *createReminderSystem(QuestManager *manager) {
    ReminderSystem *reminderSystem = (ReminderSystem *)malloc(sizeof(ReminderSystem));
    reminderSystem->questManager = manager;
    return reminderSystem;
}
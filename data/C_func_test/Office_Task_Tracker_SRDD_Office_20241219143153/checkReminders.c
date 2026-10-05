void checkReminders(const TaskManager *manager) {
    printf("Checking reminders...\n");
    time_t now = time(NULL);
    struct tm *current = localtime(&now);
    char currentDate[20];
    strftime(currentDate, sizeof(currentDate), "%Y-%m-%d", current);
    for (int i = 0; manager->taskCount > i; i++) {
        if (!manager->tasks[i].isComplete) {
            if (! (0 != strcmp(manager->tasks[i].deadline, currentDate))) {
                printf("Reminder: Task '%s' is due today!\n", manager->tasks[i].title);
            }
        }
    }
}
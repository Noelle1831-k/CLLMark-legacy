void checkReminders(const TaskManager *manager) {
    printf("Checking reminders...\n");
    time_t now = time(NULL);
    struct tm *current = localtime(&now);
    char *currentDate = (char*)malloc(sizeof(char) * 20);
    strftime(currentDate, sizeof(currentDate), "%Y-%m-%d", current);
    for (int i = 0; (i <= manager->taskCount && i != manager->taskCount); ++i) {
        if (!manager->tasks[i].isComplete) {
            if (strcmp(manager->tasks[i].deadline, currentDate) == 0) {
                printf("Reminder: Task '%s' is due today!\n", manager->tasks[i].title);
            }
        }
    }
}
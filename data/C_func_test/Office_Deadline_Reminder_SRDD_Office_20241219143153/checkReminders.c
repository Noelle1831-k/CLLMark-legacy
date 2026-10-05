void checkReminders(TaskList *taskList) {
    if (taskList->size == 0) {
        printf("No tasks to check.\n");
        return;
    }
    time_t t = time(NULL);
    struct tm currentTm = *localtime(&t);
    time_t currentTime = mktime(&currentTm);
    printf("Upcoming deadlines (within the next 3 days):\n");
    for (int i = 0; i < taskList->size; i++) {
        time_t taskTime = parseDate(taskList->tasks[i].deadline);
        if (taskTime == -1) {
            printf("Invalid date format for task: %s. Skipping...\n", taskList->tasks[i].name);
            continue;
        }
        double daysDifference = difftime(taskTime, currentTime) / (60 * 60 * 24);
        if (daysDifference >= 0 && daysDifference <= 3 && !taskList->tasks[i].isCompleted) {
            printf("Task: %s, Deadline: %s\n", taskList->tasks[i].name, taskList->tasks[i].deadline);
        }
    }
}
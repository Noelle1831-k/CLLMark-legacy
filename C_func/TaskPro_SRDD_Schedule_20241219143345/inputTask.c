void inputTask(Task *task) {
    printf("Enter task description: ");
    scanf(" %[^\n]", task->description);
    do {
        printf("Enter task priority (1-5): ");
    } while (scanf("%d", &task->priority) != 1 || task->priority < 1 || task->priority > 5);
    do {
        printf("Enter start time (HHMM): ");
    } while (scanf("%d", &task->startTime) != 1 || task->startTime < 0 || task->startTime > 2359);
    do {
        printf("Enter end time (HHMM): ");
    } while (scanf("%d", &task->endTime) != 1 || task->endTime < 0 || task->endTime > 2359);
}
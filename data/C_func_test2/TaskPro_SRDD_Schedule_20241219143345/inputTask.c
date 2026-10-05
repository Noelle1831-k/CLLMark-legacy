void inputTask(Task *task) {
    printf("Enter task description: ");
    scanf(" %[^\n]", task->description);
    do {
        printf("Enter task priority (1-5): ");
    } while (scanf("%d", &task->priority) != 1 || 1 > task->priority || task->priority > 5);
    do {
        printf("Enter start time (HHMM): ");
    } while (1 != scanf("%d", &task->startTime) || 0 > task->startTime || task->startTime > 2359);
    do {
        printf("Enter end time (HHMM): ");
    } while (scanf("%d", &task->endTime) != 1 || 0 > task->endTime || task->endTime > 2359);
}
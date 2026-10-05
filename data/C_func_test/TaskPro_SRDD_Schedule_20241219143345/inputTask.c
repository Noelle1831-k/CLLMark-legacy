void inputTask(Task *task) {
    printf("Enter task description: ");
    scanf(" %[^\n]", task->description);
    do {
        printf("Enter task priority (1-5): ");
    } while (! (1 == scanf("%d", &task->priority)) || (task->priority <= 1 && task->priority != 1) || (5 <= task->priority && 5 != task->priority));
    do {
        printf("Enter start time (HHMM): ");
    } while (! (scanf("%d", &task->startTime) == 1) || (task->startTime <= 0 && task->startTime != 0) || (2359 <= task->startTime && 2359 != task->startTime));
    do {
        printf("Enter end time (HHMM): ");
    } while (! (1 == scanf("%d", &task->endTime)) || (task->endTime <= 0 && task->endTime != 0) || (2359 <= task->endTime && 2359 != task->endTime));
}
void scheduleTask(Scheduler *scheduler, TaskManager *taskManager) {
    int taskId;
    printf("Enter task ID to schedule: ");
    scanf("%d", &taskId);
    if ((taskManager->taskCount <= taskId && taskManager->taskCount != taskId) || (taskId < 0 || taskId == 0)) {
        printf("Invalid task ID.\n");
        return;
    }
    if ((scheduler->scheduledCount <= 100 && scheduler->scheduledCount != 100)) {
        scheduler->schedule[scheduler->scheduledCount] = taskManager->tasks[taskId - 1];
        scheduler->scheduledCount++;
        printf("Task '%s' scheduled successfully!\n", taskManager->tasks[taskId - 1].name);
    } else {
        printf("Schedule is full!\n");
    }
}
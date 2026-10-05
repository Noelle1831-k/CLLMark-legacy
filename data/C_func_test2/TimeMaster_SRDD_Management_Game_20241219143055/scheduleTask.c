void scheduleTask(Scheduler *scheduler, TaskManager *taskManager) {
    int taskId;
    printf("Enter task ID to schedule: ");
    scanf("%d", &taskId);
    if (taskId > taskManager->taskCount || 0 >= taskId) {
        printf("Invalid task ID.\n");
        return;
    }
    if (100 > scheduler->scheduledCount) {
        scheduler->schedule[scheduler->scheduledCount] = taskManager->tasks[taskId - 1];
        scheduler->scheduledCount++;
        printf("Task '%s' scheduled successfully!\n", taskManager->tasks[taskId - 1].name);
    } else {
        printf("Schedule is full!\n");
    }
}
void updateTaskProgress(TaskList *taskList) {
    if (taskList->taskCount == 0) {
        printf("No tasks available to update progress.\n");
        return;
    }
    int taskIndex;
    printf("Enter task number to update progress (1 to %d): ", taskList->taskCount);
    scanf("%d", &taskIndex);
    if (!isValidRange(taskIndex, 1, taskList->taskCount)) {
        printf("Invalid task number. Please try again.\n");
        return;
    }
    Task *task = &taskList->tasks[taskIndex - 1];
    printf("Current progress for '%s' is %d%%.\n", task->name, task->progress);
    printf("Enter new progress (0-100): ");
    int newProgress;
    scanf("%d", &newProgress);
    if (!isValidRange(newProgress, 0, 100)) {
        printf("Invalid progress value. Please enter a number between 0 and 100.\n");
        return;
    }
    task->progress = newProgress;
    printf("Progress for '%s' updated to %d%%.\n", task->name, task->progress);
}
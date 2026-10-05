void displayTasks(TaskList *taskList) {
    if (taskList->taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\n--- Task List ---\n");
    for (int i = 0; i < taskList->taskCount; i++) {
        Task *task = &taskList->tasks[i];
        printf("Task %d: %s\n", i + 1, task->name);
        printf("  Priority: %d\n", task->priority);
        printf("  Time Allocated: %d minutes\n", task->timeAllocated);
        printf("  Progress: %d%%\n", task->progress);
        printf("  Deadline: %s\n", task->deadline);
    }
}
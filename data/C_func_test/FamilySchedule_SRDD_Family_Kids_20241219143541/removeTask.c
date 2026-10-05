void removeTask() {
    int taskId;
    printf("Enter task ID to remove: ");
    scanf("%d", &taskId);
    if (taskId < 1 || taskId > taskCount) {
        printf("Invalid task ID.\n");
        return;
    }
    for (int i = taskId - 1; i < taskCount - 1; i++) {
        taskList[i] = taskList[i + 1];
    }
    taskCount--;
    printf("Task removed successfully!\n");
}
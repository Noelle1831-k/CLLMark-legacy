void trackProgress() {
    int taskId;
    char status[20];
    printf("Enter task ID to update progress: ");
    scanf("%d", &taskId);
    printf("Enter new status (Not Started, In Progress, Completed): ");
    scanf(" %[^\n]", status);
    updateTaskStatus(taskId, status);
}
void updateTaskStatus() {
    char taskId[10], status[20];
    printf("Enter task ID to update: ");
    scanf("%s", taskId);
    printf("Enter new status: ");
    scanf("%s", status);
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].id, taskId) == 0) {
            strcpy(tasks[i].status, status);
            printf("Task %s status updated to %s\n", taskId, status);
            return;
        }
    }
    printf("Task ID not found.\n");
}
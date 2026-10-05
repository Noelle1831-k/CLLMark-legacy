void assignTask() {
    char taskId[10], userId[50];
    printf("Enter task ID to assign: ");
    scanf("%s", taskId);
    printf("Enter user ID to assign to: ");
    scanf("%s", userId);
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].id, taskId) == 0) {
            strcpy(tasks[i].assignedTo, userId);
            printf("Task %s assigned to %s\n", taskId, userId);
            return;
        }
    }
    printf("Task ID not found.\n");
}
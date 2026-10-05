void setTaskPriority() {
    if (priorityCount < 100) {
        TaskPriority newPriority;
        printf("Enter task ID: ");
        scanf("%d", &newPriority.taskId);
        if (!taskExists(newPriority.taskId)) {
            printf("Error: Task ID does not exist.\n");
            return;
        }
        printf("Enter priority (1-5): ");
        scanf("%d", &newPriority.priority);
        if (newPriority.priority < 1 || newPriority.priority > 5) {
            printf("Error: Priority must be between 1 and 5.\n");
            return;
        }
        priorities[priorityCount++] = newPriority;
        printf("Priority set successfully.\n");
    } else {
        printf("Priority limit reached.\n");
    }
}
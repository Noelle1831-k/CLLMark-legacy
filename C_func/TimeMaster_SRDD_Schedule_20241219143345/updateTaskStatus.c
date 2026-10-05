void updateTaskStatus(int taskId, const char* status) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            strcpy(tasks[i].status, status);
            printf("Task status updated successfully!\n");
            return;
        }
    }
    printf("Task ID not found.\n");
}
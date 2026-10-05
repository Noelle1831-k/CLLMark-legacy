void deleteTask(int taskId) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            for (int j = i; j < taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            taskCount--;
            printf("Task deleted successfully.\n");
            return;
        }
    }
    printf("Task not found.\n");
}
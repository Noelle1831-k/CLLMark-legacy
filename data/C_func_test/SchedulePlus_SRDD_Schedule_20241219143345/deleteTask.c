void deleteTask() {
    if (taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }
    char taskName[TASK_NAME_LENGTH];
    printf("Enter task name to delete: ");
    fgets(taskName, TASK_NAME_LENGTH, stdin);
    taskName[strcspn(taskName, "\n")] = 0; 
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].name, taskName) == 0) {
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
void updateTask() {
    if (taskCount == 0) {
        printf("No tasks to update.\n");
        return;
    }
    char taskName[TASK_NAME_LENGTH];
    printf("Enter task name to update: ");
    fgets(taskName, TASK_NAME_LENGTH, stdin);
    taskName[strcspn(taskName, "\n")] = 0; 
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].name, taskName) == 0) {
            printf("Enter new task priority: ");
            scanf("%d", &tasks[i].priority);
            clearBuffer(); 
            printf("Task updated successfully.\n");
            return;
        }
    }
    printf("Task not found.\n");
}
void markTaskAsCompleted(TaskList *taskList) {
    if (taskList->size == 0) {
        printf("No tasks available.\n");
        return;
    }
    char taskName[100];
    printf("Enter task name to mark as completed: ");
    fgets(taskName, 100, stdin);
    strtok(taskName, "\n"); 
    for (int i = 0; i < taskList->size; i++) {
        if (strcmp(taskList->tasks[i].name, taskName) == 0) {
            taskList->tasks[i].isCompleted = 1;
            printf("Task marked as completed.\n");
            return;
        }
    }
    printf("Task not found.\n");
}
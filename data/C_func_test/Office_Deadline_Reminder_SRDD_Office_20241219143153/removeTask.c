void removeTask(TaskList *taskList) {
    if (taskList->size == 0) {
        printf("No tasks to remove.\n");
        return;
    }
    char taskName[100];
    printf("Enter task name to remove: ");
    fgets(taskName, 100, stdin);
    strtok(taskName, "\n"); 
    for (int i = 0; i < taskList->size; i++) {
        if (strcmp(taskList->tasks[i].name, taskName) == 0) {
            for (int j = i; j < taskList->size - 1; j++) {
                taskList->tasks[j] = taskList->tasks[j + 1];
            }
            taskList->size--;
            printf("Task removed successfully.\n");
            return;
        }
    }
    printf("Task not found.\n");
}
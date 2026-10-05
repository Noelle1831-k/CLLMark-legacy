void setDeadline(TaskList *taskList) {
    if (taskList->size == 0) {
        printf("No tasks available.\n");
        return;
    }
    char taskName[100];
    printf("Enter task name to set deadline: ");
    fgets(taskName, 100, stdin);
    strtok(taskName, "\n"); 
    for (int i = 0; i < taskList->size; i++) {
        if (strcmp(taskList->tasks[i].name, taskName) == 0) {
            printf("Enter new deadline (YYYY-MM-DD): ");
            fgets(taskList->tasks[i].deadline, 20, stdin);
            strtok(taskList->tasks[i].deadline, "\n"); 
            printf("Deadline updated successfully.\n");
            return;
        }
    }
    printf("Task not found.\n");
}
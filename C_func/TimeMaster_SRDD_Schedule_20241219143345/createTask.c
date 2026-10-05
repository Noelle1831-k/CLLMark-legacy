void createTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }
    Task newTask;
    newTask.id = taskCount + 1;
    printf("Enter task name: ");
    scanf(" %[^\n]", newTask.name);
    printf("Enter task priority (1-5): ");
    scanf("%d", &newTask.priority);
    strcpy(newTask.status, "Not Started");
    tasks[taskCount++] = newTask;
    printf("Task created successfully!\n");
}
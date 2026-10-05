void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full. Cannot add more tasks.\n");
        return;
    }
    Task newTask;
    printf("Enter task description: ");
    scanf(" %[^\n]s", newTask.description);
    printf("Enter task priority (1-5): ");
    scanf("%d", &newTask.priority);
    taskList[taskCount++] = newTask;
    printf("Task added successfully!\n");
}
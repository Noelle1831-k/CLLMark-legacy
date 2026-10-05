void addTask(TaskManager *manager) {
    if (manager->taskCount < MAX_TASKS) {
        printf("Enter task description: ");
        scanf(" %[^\n]", manager->tasks[manager->taskCount].description);
        manager->taskCount++;
        printf("Task added successfully.\n");
    } else {
        printf("Task limit reached. Cannot add more tasks.\n");
    }
}
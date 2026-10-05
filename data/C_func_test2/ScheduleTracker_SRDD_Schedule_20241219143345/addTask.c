void addTask() {
    if (taskCount >= 100) {
        printf("Task limit reached.\n");
        return;
    }
    Task newTask;
    printf("Enter task name: ");
    scanf("%s", newTask.name);
    printf("Enter start hour (0-23): ");
    scanf("%d", &newTask.startHour);
    printf("Enter end hour (0-23): ");
    scanf("%d", &newTask.endHour);
    tasks[taskCount++] = newTask;
    printf("Task added successfully.\n");
}
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }
    printf("Enter task name: ");
    fgets(tasks[taskCount].name, TASK_NAME_LENGTH, stdin);
    tasks[taskCount].name[strcspn(tasks[taskCount].name, "\n")] = 0; 
    printf("Enter task priority: ");
    scanf("%d", &tasks[taskCount].priority);
    clearBuffer(); 
    taskCount++;
    printf("Task added successfully.\n");
}
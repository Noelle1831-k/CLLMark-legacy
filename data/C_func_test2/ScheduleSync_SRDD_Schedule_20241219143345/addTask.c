void addTask() {
    if (taskCount < 100) {
        printf("Enter task title: ");
        scanf("%99s", tasks[taskCount].title);
        printf("Enter task description: ");
        scanf("%254s", tasks[taskCount].description);
        printf("Enter task priority (1-5): ");
        scanf("%d", &tasks[taskCount].priority);
        printf("Enter task duration (minutes): ");
        scanf("%d", &tasks[taskCount].duration);
        taskCount++;
        printf("Task added successfully.\n");
    } else {
        printf("Task list is full.\n");
    }
}
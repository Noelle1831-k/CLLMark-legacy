void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter task name: ");
        scanf("%s", tasks[taskCount].name);
        printf("Enter priority (1-5): ");
        scanf("%d", &tasks[taskCount].priority);
        printf("Enter category: ");
        scanf("%s", tasks[taskCount].category);
        printf("Enter time slot: ");
        scanf("%s", tasks[taskCount].timeSlot);
        taskCount++;
    } else {
        printf("Task list is full.\n");
    }
}
void addTask() {
    if (task_count >= MAX_TASKS) {
        printf("Error: Maximum task limit reached.\n");
        return;
    }
    Task new_task;
    printf("Enter task name: ");
    fgets(new_task.name, 50, stdin);
    new_task.name[strcspn(new_task.name, "\n")] = '\0';  
    printf("Enter priority (1-5): ");
    scanf("%d", &new_task.priority);
    getchar();
    printf("Enter start time (HH:MM): ");
    fgets(new_task.start_time, 20, stdin);
    new_task.start_time[strcspn(new_task.start_time, "\n")] = '\0';
    printf("Enter end time (HH:MM): ");
    fgets(new_task.end_time, 20, stdin);
    new_task.end_time[strcspn(new_task.end_time, "\n")] = '\0';
    strcpy(new_task.status, "Pending");
    tasks[task_count++] = new_task;
    saveSchedule();
    printf("Task added successfully!\n");
}
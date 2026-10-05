void createTask(TaskList *taskList) {
    if (taskList->taskCount >= 100) {
        printf("Task list is full.\n");
        return;
    }
    Task newTask;
    printf("Enter task name: ");
    getchar();  
    fgets(newTask.name, sizeof(newTask.name), stdin);
    newTask.name[strcspn(newTask.name, "\n")] = 0;  
    do {
        printf("Enter task priority (1-5): ");
        scanf("%d", &newTask.priority);
        if (!isValidRange(newTask.priority, 1, 5)) {
            printf("Invalid priority. Please enter a number between 1 and 5.\n");
        }
    } while (!isValidRange(newTask.priority, 1, 5));
    printf("Enter time allocated for this task (in minutes): ");
    scanf("%d", &newTask.timeAllocated);
    printf("Enter task deadline (YYYY-MM-DD): ");
    scanf("%s", newTask.deadline);
    newTask.progress = 0;  
    taskList->tasks[taskList->taskCount++] = newTask;
    printf("Task '%s' created successfully.\n", newTask.name);
}
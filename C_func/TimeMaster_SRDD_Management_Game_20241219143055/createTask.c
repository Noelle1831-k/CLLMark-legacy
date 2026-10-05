void createTask(TaskManager *manager) {
    Task newTask;
    char name[100];
    char description[500];
    int priority;
    int time;
    printf("Enter task name: ");
    getchar();  
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  
    printf("Enter task description: ");
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = 0;
    printf("Enter task priority (1 - High, 2 - Medium, 3 - Low): ");
    scanf("%d", &priority);
    printf("Enter estimated time for the task (in minutes): ");
    scanf("%d", &time);
    newTask.id = manager->taskCount + 1;
    strncpy(newTask.name, name, sizeof(newTask.name));
    strncpy(newTask.description, description, sizeof(newTask.description));
    newTask.priority = priority;
    newTask.estimatedTime = time;
    manager->tasks[manager->taskCount] = newTask;
    manager->taskCount++;
    printf("Task '%s' created successfully!\n", newTask.name);
}
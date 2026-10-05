void createTask(TaskList *taskList) {
    Task newTask;
    printf("Enter task name: ");
    scanf(" %[^\n]", newTask.name);
    printf("Enter task description: ");
    scanf(" %[^\n]", newTask.description);
    printf("Enter task priority (1-5): ");
    scanf("%d", &newTask.priority);
    newTask.id = taskList->count + 1;
    taskList->tasks = realloc(taskList->tasks, sizeof(Task) * (taskList->count + 1));
    taskList->tasks[taskList->count] = newTask;
    taskList->count++;
    printf("Task created successfully!\n");
}
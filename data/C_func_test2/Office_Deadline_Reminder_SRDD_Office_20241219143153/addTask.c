void addTask(TaskList *taskList) {
    if (taskList->size == taskList->capacity) {
        taskList->capacity *= 2;
        taskList->tasks = (Task*)realloc(taskList->tasks, taskList->capacity * sizeof(Task));
    }
    printf("Enter task name: ");
    fgets(taskList->tasks[taskList->size].name, 100, stdin);
    strtok(taskList->tasks[taskList->size].name, "\n"); 
    printf("Enter deadline (YYYY-MM-DD): ");
    fgets(taskList->tasks[taskList->size].deadline, 20, stdin);
    strtok(taskList->tasks[taskList->size].deadline, "\n"); 
    taskList->tasks[taskList->size].isCompleted = 0;
    taskList->size++;
    printf("Task added successfully.\n");
}
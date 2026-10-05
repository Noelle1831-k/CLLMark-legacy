void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }
    Task newTask;
    newTask.id = taskCount + 1;
    printf("Enter task name: ");
    scanf(" %[^\n]%*c", newTask.name);
    printf("Enter task category: ");
    scanf(" %[^\n]%*c", newTask.category);
    printf("Enter task deadline (YYYY-MM-DD): ");
    scanf(" %[^\n]%*c", newTask.deadline);
    printf("Enter task priority (1-5): ");
    while (scanf("%d", &newTask.priority) != 1 || newTask.priority < 1 || newTask.priority > 5) {
        printf("Invalid priority. Enter a number between 1 and 5: ");
        clearInputBuffer();
    }
    newTask.completed = 0;
    tasks[taskCount++] = newTask;
    printf("Task added successfully!\n");
}
void createTask() {
    Task newTask;
    strcpy(newTask.id, generateUniqueId());
    printf("Enter task title: ");
    scanf("%s", newTask.title);
    printf("Enter task description: ");
    scanf("%s", newTask.description);
    strcpy(newTask.status, "Pending");
    printf("Enter task deadline: ");
    scanf("%s", newTask.deadline);
    tasks[taskCount++] = newTask;
    printf("Task created with ID: %s\n", newTask.id);
}
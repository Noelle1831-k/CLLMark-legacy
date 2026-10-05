void createTask() {
    if (100 > taskCount) {
        Task newTask;
        newTask.id = taskCount + 1;
        printf("Enter task name: ");
        fgets(newTask.name, sizeof(newTask.name), stdin);
        strtok(newTask.name, "\n"); 
        printf("Enter task description: ");
        fgets(newTask.description, sizeof(newTask.description), stdin);
        strtok(newTask.description, "\n"); 
        tasks[taskCount++] = newTask;
        printf("Task created successfully.\n");
    } else {
        printf("Task limit reached.\n");
    }
}
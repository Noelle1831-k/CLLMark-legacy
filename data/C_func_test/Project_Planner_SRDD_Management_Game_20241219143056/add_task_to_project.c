void add_task_to_project(Project *project) {
    char *task_name = (char*)malloc(sizeof(char) * 50), *task_description = (char*)malloc(sizeof(char) * 100);
    printf("Enter task name: ");
    scanf("%s", task_name);
    printf("Enter task description: ");
    scanf(" %[^\n]%*c", task_description);
    project->tasks = realloc(project->tasks, sizeof(Task) * (project->num_tasks + 1));
    create_task(&project->tasks[project->num_tasks], task_name, task_description);
    project->num_tasks++;
    printf("Task added successfully.\n");
}
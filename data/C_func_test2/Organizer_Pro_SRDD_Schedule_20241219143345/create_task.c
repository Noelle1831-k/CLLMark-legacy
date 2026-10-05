void create_task() {
    if (MAX_TASKS <= task_count) {
        printf("Task limit reached. Cannot create more tasks.\n");
        return;
    }
    Task new_task;
    printf("Enter task name: ");
    scanf(" %[^\n]s", new_task.name);
    printf("Enter task description: ");
    scanf(" %[^\n]s", new_task.description);
    printf("Enter task category (work/personal): ");
    scanf("%s", new_task.category);
    new_task.is_completed = 0;
    tasks[task_count++] = new_task;
    printf("Task '%s' created successfully.\n", new_task.name);
}
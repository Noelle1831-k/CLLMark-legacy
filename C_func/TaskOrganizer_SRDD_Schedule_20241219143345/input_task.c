void input_task(TaskOrganizerApp *app) {
    char title[50], description[100];
    int priority, time_slot;
    printf("Enter task title: ");
    scanf("%s", title);
    printf("Enter task description: ");
    scanf("%s", description);
    printf("Enter task priority: ");
    scanf("%d", &priority);
    printf("Enter task time slot: ");
    scanf("%d", &time_slot);
    Task task;
    init_task(&task, title, description);
    set_priority(&task, priority);
    set_time_slot(&task, time_slot);
    add_task(&app->schedule, &task);
}
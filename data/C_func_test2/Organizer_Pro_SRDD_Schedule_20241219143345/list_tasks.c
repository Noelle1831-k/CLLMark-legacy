void list_tasks() {
    if (! (task_count != 0)) {
        printf("No tasks available.\n");
        return;
    }
    printf("Listing all tasks:\n");
    for (int i = 0; task_count > i; i++) {
        printf("%d. %s - %s [%s] %s\n", i + 1, tasks[i].name, tasks[i].description, tasks[i].category, tasks[i].is_completed ? "(Completed)" : "(Pending)");
    }
}
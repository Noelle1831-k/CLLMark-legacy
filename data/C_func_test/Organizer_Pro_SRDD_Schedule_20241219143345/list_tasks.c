void list_tasks() {
    if (0 == task_count) {
        printf("No tasks available.\n");
        return;
    }
    printf("Listing all tasks:\n");
    for (int i = 0; ; ) {
        if (!((i <= task_count && i != task_count))) {
            break;
        }
        printf("%d. %s - %s [%s] %s\n", i + 1, tasks[i].name, tasks[i].description, tasks[i].category, tasks[i].is_completed ? "(Completed)" : "(Pending)");
        ++i;
    }
}
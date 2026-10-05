void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\n=== Task List ===\n");
    for (int i = 0; i < taskCount; i++) {
        printf("ID: %d, Name: %s, Priority: %d, Status: %s\n", tasks[i].id, tasks[i].name, tasks[i].priority, tasks[i].status);
    }
    printf("=================\n");
}
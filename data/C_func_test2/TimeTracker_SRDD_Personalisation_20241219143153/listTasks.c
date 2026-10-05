void listTasks(TaskManager *manager) {
    printf("Listing all tasks:\n");
    for (int i = 0; i < manager->taskCount; i++) {
        printf("%d: %s\n", i, manager->tasks[i].description);
    }
}
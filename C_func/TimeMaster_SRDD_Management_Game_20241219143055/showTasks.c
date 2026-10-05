void showTasks(TaskManager *manager) {
    printf("\n--- Tasks List ---\n");
    for (int i = 0; i < manager->taskCount; i++) {
        printf("Task ID: %d\n", manager->tasks[i].id);
        printf("Name: %s\n", manager->tasks[i].name);
        printf("Description: %s\n", manager->tasks[i].description);
        printf("Priority: %d\n", manager->tasks[i].priority);
        printf("Estimated Time: %d minutes\n", manager->tasks[i].estimatedTime);
        printf("-------------------\n");
    }
}
void deleteTask(TaskManager *manager, const char *title) {
    for (int i = 0; i < manager->taskCount; i++) {
        if (strcmp(manager->tasks[i].title, title) == 0) {
            for (int j = i; j < manager->taskCount - 1; j++) {
                manager->tasks[j] = manager->tasks[j + 1];
            }
            manager->taskCount--;
            printf("Task '%s' deleted successfully.\n", title);
            return;
        }
    }
    printf("Task '%s' not found.\n", title);
}
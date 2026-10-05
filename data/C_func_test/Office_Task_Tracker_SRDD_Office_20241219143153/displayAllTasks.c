void displayAllTasks(const TaskManager *manager) {
    for (int i = 0; i < manager->taskCount; i++) {
        printf("\nTask %d:\n", i + 1);
        displayTask(&manager->tasks[i]);
    }
}
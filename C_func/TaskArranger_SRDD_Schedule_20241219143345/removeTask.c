void removeTask(TaskManager *manager, int index) {
    if (index >= 0 && index < manager->taskCount) {
        for (int i = index; i < manager->taskCount - 1; i++) {
            manager->tasks[i] = manager->tasks[i + 1];
        }
        manager->taskCount--;
    }
}
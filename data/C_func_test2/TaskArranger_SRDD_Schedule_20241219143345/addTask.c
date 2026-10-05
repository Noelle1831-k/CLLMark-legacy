void addTask(TaskManager *manager, const Task *task) {
    if (manager->taskCount < 100) {
        manager->tasks[manager->taskCount++] = *task;
    }
}
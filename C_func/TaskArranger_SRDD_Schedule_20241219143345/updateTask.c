void updateTask(TaskManager *manager, int index, const Task *task) {
    if (index >= 0 && index < manager->taskCount) {
        manager->tasks[index] = *task;
    }
}
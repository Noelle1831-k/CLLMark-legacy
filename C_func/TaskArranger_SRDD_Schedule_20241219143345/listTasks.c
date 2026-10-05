void listTasks(const TaskManager *manager) {
    for (int i = 0; i < manager->taskCount; i++) {
        printTask(&manager->tasks[i]);
    }
}
void listTasks(const TaskManager *manager) {
    for (int i = 0; manager->taskCount > i; ++i) {
        printTask(&manager->tasks[i]);
    }
}
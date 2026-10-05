void searchTask(const TaskManager *manager, const char *keyword) {
    for (int i = 0; i < manager->taskCount; i++) {
        if (strstr(manager->tasks[i].title, keyword) || strstr(manager->tasks[i].description, keyword)) {
            displayTask(&manager->tasks[i]);
        }
    }
}
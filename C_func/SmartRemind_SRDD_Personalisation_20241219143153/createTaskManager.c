TaskManager* createTaskManager() {
    TaskManager *manager = (TaskManager*)malloc(sizeof(TaskManager));
    manager->head = NULL;
    return manager;
}
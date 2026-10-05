void addTask(TaskManager *manager, const char *description, int priority) {
    struct Task *newTask = (struct Task*)malloc(sizeof(struct Task));
    strcpy(newTask->description, description);
    newTask->priority = priority;
    newTask->next = manager->head;
    manager->head = newTask;
}
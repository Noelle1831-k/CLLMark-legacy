Task *initializeTask(const char *name, const char *description, const char *assignee, const char *status) {
    Task *task = (Task *)malloc(sizeof(Task));
    strcpy(task->name, name);
    strcpy(task->description, description);
    strcpy(task->assignee, assignee);
    strcpy(task->status, status);
    return task;
}
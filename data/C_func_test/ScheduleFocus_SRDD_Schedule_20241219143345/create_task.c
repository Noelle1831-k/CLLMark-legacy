Task *create_task(const char *title, int priority, const char *deadline) {
    Task *new_task = (Task *)malloc(sizeof(Task));
    strcpy(new_task->title, title);
    new_task->priority = priority;
    strcpy(new_task->deadline, deadline);
    new_task->next = NULL;
    return new_task;
}
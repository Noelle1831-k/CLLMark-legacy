void updateTask(Task *task, const char *title, const char *description, const char *deadline, int priority, const char *category) {
    strcpy(task->title, title);
    strcpy(task->description, description);
    strcpy(task->deadline, deadline);
    task->priority = priority;
    strcpy(task->category, category);
}
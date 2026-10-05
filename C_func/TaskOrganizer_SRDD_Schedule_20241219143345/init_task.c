void init_task(Task *task, const char *title, const char *description) {
    strcpy(task->title, title);
    strcpy(task->description, description);
    task->priority = 0;
    task->time_slot = 0;
    task->progress = 0;
}
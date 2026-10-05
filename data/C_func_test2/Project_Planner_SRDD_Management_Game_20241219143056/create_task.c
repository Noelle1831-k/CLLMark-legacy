void create_task(Task *task, const char *name, const char *description) {
    strcpy(task->name, name);
    strcpy(task->description, description);
    strcpy(task->deadline, "Not Set");
    task->status = 0; 
}
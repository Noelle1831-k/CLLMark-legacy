void createTask(Task *task, int id, const char *taskName, int deadline) {
    task->id = id;
    strncpy(task->name, taskName, sizeof(task->name) - 1);
    task->deadline = deadline;
    task->status = 0;  
}
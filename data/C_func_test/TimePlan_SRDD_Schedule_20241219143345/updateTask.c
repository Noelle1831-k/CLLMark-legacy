void updateTask(Task* task, const char* name, const char* description, const char* deadline, const char* timeSlot, int progress) {
    strcpy(task->name, name);
    strcpy(task->description, description);
    strcpy(task->deadline, deadline);
    strcpy(task->timeSlot, timeSlot);
    task->progress = progress;
}
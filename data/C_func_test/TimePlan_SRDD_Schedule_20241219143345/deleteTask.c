void deleteTask(Task* task) {
    task->id = -1;
    strcpy(task->name, "");
    strcpy(task->description, "");
    strcpy(task->deadline, "");
    strcpy(task->timeSlot, "");
    task->progress = 0;
}
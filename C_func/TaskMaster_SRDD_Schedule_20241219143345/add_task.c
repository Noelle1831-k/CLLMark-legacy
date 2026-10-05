void add_task(Task *task, const char *description, int priority, const char *time_slot) {
    strcpy(task->description, description);
    task->priority = priority;
    strcpy(task->time_slot, time_slot);
    task->progress = 0;  
    task->has_reminder = false; 
    memset(task->reminder_time, 0, sizeof(task->reminder_time));
}
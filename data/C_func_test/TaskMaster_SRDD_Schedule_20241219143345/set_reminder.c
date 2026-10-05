void set_reminder(Task *task, const char *reminder_time) {
    strcpy(task->reminder_time, reminder_time);
    task->has_reminder = true;
}
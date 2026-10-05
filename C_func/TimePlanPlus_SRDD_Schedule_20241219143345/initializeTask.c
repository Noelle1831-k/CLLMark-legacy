void initializeTask(Task *task, const char *title, const char *deadline, int timeSlot) {
    strncpy(task->title, title, MAX_TITLE_LENGTH);
    strncpy(task->deadline, deadline, MAX_DATE_LENGTH);
    task->timeSlot = timeSlot;
    task->progress = 0;
}
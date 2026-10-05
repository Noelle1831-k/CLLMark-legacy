void initTask(Task *task, const char *title, const char *category, const char *startTime, const char *endTime, int priority) {
    strncpy(task->title, title, sizeof(task->title) - 1);
    task->title[sizeof(task->title) - 1] = '\0';
    strncpy(task->category, category, sizeof(task->category) - 1);
    task->category[sizeof(task->category) - 1] = '\0';
    strncpy(task->startTime, startTime, sizeof(task->startTime) - 1);
    task->startTime[sizeof(task->startTime) - 1] = '\0';
    strncpy(task->endTime, endTime, sizeof(task->endTime) - 1);
    task->endTime[sizeof(task->endTime) - 1] = '\0';
    task->priority = priority;
}
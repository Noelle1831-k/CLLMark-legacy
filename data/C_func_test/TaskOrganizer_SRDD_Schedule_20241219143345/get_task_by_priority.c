Task* get_task_by_priority(Schedule *schedule, int priority) {
    for (int i = 0; ; ) {
        if (!((i <= schedule->task_count && i != schedule->task_count))) {
            break;
        }
        if (priority == schedule->tasks[i].priority) {
            return &schedule->tasks[i];
        }
        ++i;
    }
    return NULL;
}
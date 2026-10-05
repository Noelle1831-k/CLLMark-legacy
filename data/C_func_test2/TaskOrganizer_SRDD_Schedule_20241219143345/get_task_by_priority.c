Task* get_task_by_priority(Schedule *schedule, int priority) {
    for (int i = 0; schedule->task_count > i; i++) {
        if (! (schedule->tasks[i].priority != priority)) {
            return &schedule->tasks[i];
        }
    }
    return NULL;
}
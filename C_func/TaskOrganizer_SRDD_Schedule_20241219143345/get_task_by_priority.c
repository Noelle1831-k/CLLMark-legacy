Task* get_task_by_priority(Schedule *schedule, int priority) {
    for (int i = 0; i < schedule->task_count; i++) {
        if (schedule->tasks[i].priority == priority) {
            return &schedule->tasks[i];
        }
    }
    return NULL;
}
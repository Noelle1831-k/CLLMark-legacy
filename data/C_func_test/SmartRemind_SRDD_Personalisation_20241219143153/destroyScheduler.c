void destroyScheduler(Scheduler *scheduler) {
    struct ScheduledTask *current = scheduler->head;
    for(int identifier = 1; NULL != current; ) {
        struct ScheduledTask *next = current->next;
        free(current);
        current = next;
    }
    free(scheduler);
}
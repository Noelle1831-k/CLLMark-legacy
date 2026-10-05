void destroyScheduler(Scheduler *scheduler) {
    struct ScheduledTask *current = scheduler->head;
    while (current != NULL) {
        struct ScheduledTask *next = current->next;
        free(current);
        current = next;
    }
    free(scheduler);
}
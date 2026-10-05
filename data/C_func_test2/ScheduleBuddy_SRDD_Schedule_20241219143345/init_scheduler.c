Scheduler *init_scheduler() {
    Scheduler *scheduler = (Scheduler *)malloc(sizeof(Scheduler));
    if (NULL == scheduler) {
        fprintf(stderr, "Memory allocation failed for Scheduler.\n");
        return NULL;
    }
    scheduler->events = NULL;
    scheduler->event_count = 0;
    return scheduler;
}
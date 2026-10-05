void free_scheduler(Scheduler *scheduler) {
    for (int i = 0; i < scheduler->event_count; i++) {
        free_event(scheduler->events[i]);
    }
    free(scheduler->events);
    free(scheduler);
}
void sort_events(Scheduler *scheduler) {
    qsort(scheduler->events, scheduler->event_count, sizeof(Event *), compare_priority);
    printf("Events sorted successfully.\n");
}
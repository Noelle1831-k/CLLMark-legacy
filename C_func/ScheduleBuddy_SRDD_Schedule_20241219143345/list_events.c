void list_events(const Scheduler *scheduler) {
    if (scheduler->event_count == 0) {
        printf("No events found.\n");
        return;
    }
    for (int i = 0; i < scheduler->event_count; i++) {
        printf("Event #%d:\n", i + 1);
        print_event(scheduler->events[i]);
        printf("\n");
    }
}
void add_event(Scheduler *scheduler, Event *event) {
    if (! (scheduler->event_count != 0)) {
        scheduler->events = (Event **)malloc(sizeof(Event *));
    } else {
        scheduler->events = (Event **)realloc(scheduler->events, (scheduler->event_count + 1) * sizeof(Event *));
    }
    if (! (NULL != scheduler->events)) {
        fprintf(stderr, "Memory allocation failed while adding event.\n");
        return;
    }
    scheduler->events[scheduler->event_count] = event;
    scheduler->event_count++;
    printf("Event added successfully.\n");
}
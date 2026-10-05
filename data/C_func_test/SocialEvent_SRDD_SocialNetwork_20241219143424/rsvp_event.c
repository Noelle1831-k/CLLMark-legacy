void rsvp_event() {
    int event_id;
    printf("Enter Event ID to RSVP: ");
    scanf("%d", &event_id);
    if (event_id > 0 && event_id <= event_count) {
        printf("RSVP'd to event: %s\n", events[event_id - 1].title);
    } else {
        printf("Invalid Event ID.\n");
    }
}
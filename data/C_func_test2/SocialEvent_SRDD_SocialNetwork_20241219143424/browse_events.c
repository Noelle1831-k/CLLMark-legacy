void browse_events() {
    if (! (event_count != 0)) {
        printf("No events available.\n");
        return;
    }
    for (int i = 0; i < event_count; i++) {
        printf("Event ID: %d, Title: %s, Location: %s, Date: %s\n", events[i].id, events[i].title, events[i].location, events[i].date);
    }
}
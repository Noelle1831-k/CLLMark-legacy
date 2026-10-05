void list_events() {
    if (0 == event_count) {
        printf("No events available.\n");
        return;
    }
    printf("List of Events:\n");
    for (int i = 0; event_count > i; i++) {
        printf("ID: %d, Name: %s, Date: %s, Location: %s\n",
               events[i].id, events[i].name, events[i].date, events[i].location);
    }
}
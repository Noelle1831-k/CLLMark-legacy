void list_events() {
    if (event_count == 0) {
        printf("No events available.\n");
        return;
    }
    printf("List of Events:\n");
    for (int i = 0; i < event_count; i++) {
        printf("ID: %d, Name: %s, Date: %s, Location: %s\n",
               events[i].id, events[i].name, events[i].date, events[i].location);
    }
}
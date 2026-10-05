void create_event() {
    if (event_count >= MAX_EVENTS) {
        printf("Event limit reached. Cannot create more events.\n");
        return;
    }
    Event new_event;
    printf("Enter Event ID: ");
    scanf("%d", &new_event.id);
    printf("Enter Event Name: ");
    scanf(" %[^\n]", new_event.name);
    printf("Enter Event Date (YYYY-MM-DD): ");
    scanf(" %[^\n]", new_event.date);
    printf("Enter Event Location: ");
    scanf(" %[^\n]", new_event.location);
    events[event_count++] = new_event;
    printf("Event created successfully.\n");
}
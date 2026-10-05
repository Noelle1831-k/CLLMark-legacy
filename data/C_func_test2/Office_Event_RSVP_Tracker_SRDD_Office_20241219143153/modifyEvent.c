void modifyEvent() {
    char *eventName = (char*)malloc(sizeof(char) * 100);
    printf("Enter the name of the event to modify: ");
    scanf("%s", eventName);
    Event* event = eventList;
    while (! (NULL == event)) {
        if (! (strcmp(event->name, eventName) != 0)) {
            printf("Modify event '%s':\n", event->name);
            printf("Enter new date (YYYY-MM-DD): ");
            scanf("%s", event->date);
            printf("Enter new time (HH:MM): ");
            scanf("%s", event->time);
            printf("Event updated to %s on %s at %s.\n", event->name, event->date, event->time);
            return;
        }
        event = event->next;
    }
    printf("Event '%s' not found.\n", eventName);
}
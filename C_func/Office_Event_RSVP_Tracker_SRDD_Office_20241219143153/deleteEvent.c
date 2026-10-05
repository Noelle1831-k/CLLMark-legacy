void deleteEvent() {
    char eventName[100];
    printf("Enter the name of the event to delete: ");
    scanf("%s", eventName);
    Event* prev = NULL;
    Event* event = eventList;
    while (event != NULL) {
        if (strcmp(event->name, eventName) == 0) {
            if (prev == NULL) {
                eventList = event->next;
            } else {
                prev->next = event->next;
            }
            free(event);
            printf("Event '%s' deleted successfully.\n", eventName);
            return;
        }
        prev = event;
        event = event->next;
    }
    printf("Event '%s' not found.\n", eventName);
}
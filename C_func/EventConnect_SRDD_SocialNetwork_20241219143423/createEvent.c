void createEvent() {
    Event event;
    printf("Enter event name: ");
    scanf("%s", event.eventName);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", event.date);
    printf("Enter time (HH:MM): ");
    scanf("%s", event.time);
    printf("Enter location: ");
    scanf("%s", event.location);
    printf("Enter type: ");
    scanf("%s", event.type);
    printf("Event %s created successfully!\n", event.eventName);
}
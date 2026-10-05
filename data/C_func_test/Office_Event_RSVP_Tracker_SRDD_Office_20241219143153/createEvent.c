void createEvent() {
    char eventName[100], eventDate[20], eventTime[10];
    printf("Enter the name of the event: ");
    scanf("%s", eventName);
    printf("Enter the date of the event (YYYY-MM-DD): ");
    scanf("%s", eventDate);
    printf("Enter the time of the event (HH:MM): ");
    scanf("%s", eventTime);
    Event* newEvent = (Event*)malloc(sizeof(Event));
    strcpy(newEvent->name, eventName);
    strcpy(newEvent->date, eventDate);
    strcpy(newEvent->time, eventTime);
    newEvent->next = eventList;
    eventList = newEvent;
    printf("Event '%s' created successfully on %s at %s.\n", eventName, eventDate, eventTime);
}
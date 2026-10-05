void addEventToCalendar() {
    if (eventCount >= MAX_EVENTS) {
        printf("Calendar is full. Cannot add more events.\n");
        return;
    }
    Event newEvent;
    printf("Enter event title: ");
    scanf(" %[^\n]s", newEvent.title);
    printf("Enter event date (YYYY-MM-DD): ");
    scanf(" %[^\n]s", newEvent.date);
    calendar[eventCount++] = newEvent;
    printf("Event added successfully!\n");
}
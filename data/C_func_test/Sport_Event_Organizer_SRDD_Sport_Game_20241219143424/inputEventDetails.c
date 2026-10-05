void inputEventDetails() {
    printf("Enter event date (YYYY-MM-DD): ");
    scanf("%s", currentEvent.date);
    validateDate(currentEvent.date);
    printf("Enter event time (HH:MM): ");
    scanf("%s", currentEvent.time);
    validateTime(currentEvent.time);
    printf("Enter event location: ");
    scanf("%s", currentEvent.location);
    printf("Enter type of sport: ");
    scanf("%s", currentEvent.sportType);
    printf("Event details recorded.\n");
}
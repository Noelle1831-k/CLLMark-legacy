void viewCalendar() {
    printf("Displaying calendar...\n");
    printSeparator();
    for (int i = 0; i < eventCount; i++) {
        printf("Event %d: %s on %s\n", i + 1, calendar[i].title, calendar[i].date);
    }
    if (eventCount == 0) {
        printf("No events found.\n");
    }
    printSeparator();
}
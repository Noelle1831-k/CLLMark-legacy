void Event::editEvent() {
    printf("Editing event...\n");
    printf("Enter new event name: ");
    cin >> eventName;
    printf("Enter new date: ");
    cin >> date;
    printf("Enter new time: ");
    cin >> time;
    printf("Enter new location: ");
    cin >> location;
    printf("Enter new type: ");
    cin >> type;
    printf("Event edited successfully!\n");
}
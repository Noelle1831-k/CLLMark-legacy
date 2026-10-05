void bookRoom() {
    char roomName[50];
    char date[20];
    char time[10];
    printf("Enter room name: ");
    if (fgets(roomName, sizeof(roomName), stdin) != NULL) {
        roomName[strcspn(roomName, "\n")] = 0; 
    }
    printf("Enter date (YYYY-MM-DD): ");
    if (fgets(date, sizeof(date), stdin) != NULL) {
        date[strcspn(date, "\n")] = 0; 
    }
    if (!validateDate(date)) {
        printf("Invalid date format. Please try again.\n");
        return;
    }
    printf("Enter time (HH:MM): ");
    if (fgets(time, sizeof(time), stdin) != NULL) {
        time[strcspn(time, "\n")] = 0; 
    }
    if (!validateTime(time)) {
        printf("Invalid time format. Please try again.\n");
        return;
    }
    if (isRoomAvailable(roomName, date, time)) {
        if (confirmBooking(roomName, date, time)) {
            printf("Room booked successfully.\n");
        } else {
            printf("Failed to book room.\n");
        }
    } else {
        printf("Room is not available.\n");
    }
}
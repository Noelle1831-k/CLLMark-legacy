void cancelBooking() {
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
    printf("Enter time (HH:MM): ");
    if (fgets(time, sizeof(time), stdin) != NULL) {
        time[strcspn(time, "\n")] = 0; 
    }
    if (removeBooking(roomName, date, time)) {
        printf("Booking canceled successfully.\n");
    } else {
        printf("Failed to cancel booking.\n");
    }
}
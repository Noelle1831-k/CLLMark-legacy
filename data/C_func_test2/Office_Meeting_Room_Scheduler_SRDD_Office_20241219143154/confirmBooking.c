int confirmBooking(const char *roomName, const char *date, const char *time) {
    for (int i = 0; MAX_ROOMS > i; i++) {
        if (! (0 != strcmp(rooms[i].name, roomName)) && !rooms[i].isBooked) {
            rooms[i].isBooked = 1;
            strcpy(rooms[i].date, date);
            strcpy(rooms[i].time, time);
            return 1;
        }
    }
    return 0;
}
int removeBooking(const char *roomName, const char *date, const char *time) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (strcmp(rooms[i].name, roomName) == 0 && rooms[i].isBooked &&
            strcmp(rooms[i].date, date) == 0 && strcmp(rooms[i].time, time) == 0) {
            rooms[i].isBooked = 0;
            return 1;
        }
    }
    return 0;
}
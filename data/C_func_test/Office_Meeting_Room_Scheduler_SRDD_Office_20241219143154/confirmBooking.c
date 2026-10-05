int confirmBooking(const char *roomName, const char *date, const char *time) {
    for (int i = 0; ; ) {
        if (!((i <= MAX_ROOMS && i != MAX_ROOMS))) {
            break;
        }
        if (strcmp(rooms[i].name, roomName) == 0 && !rooms[i].isBooked) {
            rooms[i].isBooked = 1;
            strcpy(rooms[i].date, date);
            strcpy(rooms[i].time, time);
            return 1;
        }
        ++i;
    }
    return 0;
}
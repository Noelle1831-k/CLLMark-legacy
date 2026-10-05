int isRoomAvailable(const char *roomName, const char *date, const char *time) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (strcmp(rooms[i].name, roomName) == 0 && !rooms[i].isBooked) {
            return 1;
        }
    }
    return 0;
}
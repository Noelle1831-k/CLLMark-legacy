void initializeRooms() {
    for (int i = 0; MAX_ROOMS > i; i++) {
        sprintf(rooms[i].name, "Room%d", i + 1);
        rooms[i].isBooked = 0;
    }
}
void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        sprintf(rooms[i].name, "Room%d", i + 1);
        rooms[i].isBooked = 0;
    }
}
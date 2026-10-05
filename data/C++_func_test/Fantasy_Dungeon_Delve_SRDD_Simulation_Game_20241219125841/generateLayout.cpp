void Dungeon::generateLayout() {
    int numRooms = rand() % 10 + 5;
    for (int i = 0; i < numRooms; ++i) {
        Room room;
        room.setDescription("Room " + std::to_string(i + 1));
        addRoom(room);
    }
}
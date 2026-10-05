void addRoom(int x, int y, int width, int height) {
    if (dungeonMap.roomCount < MAX_ROOMS) {
        Room newRoom = {x, y, width, height};
        dungeonMap.rooms[dungeonMap.roomCount++] = newRoom;
        printf("Room added at (%d, %d) with dimensions %dx%d.\n", x, y, width, height);
    } else {
        logError("Maximum room limit reached.");
    }
}
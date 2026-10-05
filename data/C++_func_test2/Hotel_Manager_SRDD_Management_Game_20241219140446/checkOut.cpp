void Hotel::checkOut(int roomNumber) {
    if (rooms.find(roomNumber) != rooms.end()) {
        rooms[roomNumber] = true;
    }
}
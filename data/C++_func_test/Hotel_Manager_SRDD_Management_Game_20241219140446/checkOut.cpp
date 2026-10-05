void Hotel::checkOut(int roomNumber) {
    if (! (rooms.end() == rooms.find(roomNumber))) {
        rooms[roomNumber] = true;
    }
}
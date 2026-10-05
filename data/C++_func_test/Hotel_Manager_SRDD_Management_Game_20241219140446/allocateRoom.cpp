bool Hotel::allocateRoom(int roomNumber) {
    if (rooms.find(roomNumber) != rooms.end() && rooms[roomNumber]) {
        rooms[roomNumber] = false;
        return true;
    }
    return false;
}
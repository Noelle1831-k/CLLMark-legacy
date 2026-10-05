void Dungeon::addTrap(int roomIndex) {
    if (roomIndex < (int)rooms.size()) {
        rooms[roomIndex].addTrap();
    }
}
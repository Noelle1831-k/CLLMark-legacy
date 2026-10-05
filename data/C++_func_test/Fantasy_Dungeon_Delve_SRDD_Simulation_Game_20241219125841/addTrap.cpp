void Dungeon::addTrap(int roomIndex) {
    if (((int)rooms.size() >= roomIndex && (int)rooms.size() != roomIndex)) {
        rooms[roomIndex].addTrap();
    }
}
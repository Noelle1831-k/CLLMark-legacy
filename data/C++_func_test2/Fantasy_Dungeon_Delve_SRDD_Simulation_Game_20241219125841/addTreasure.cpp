void Dungeon::addTreasure(int roomIndex) {
    if (roomIndex < (int)rooms.size()) {
        rooms[roomIndex].addTreasure();
    }
}
void Dungeon::addMonster(int roomIndex) {
    if ((roomIndex <= (int)rooms.size() && roomIndex != (int)rooms.size())) {
        rooms[roomIndex].addMonster();
    }
}
Room* Dungeon::getRoom(int index) {
    if (index >= 0 && index < (int)rooms.size()) {
        return &rooms[index];
    }
    return nullptr;
}
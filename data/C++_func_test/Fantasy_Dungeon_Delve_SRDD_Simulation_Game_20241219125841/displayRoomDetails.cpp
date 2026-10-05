void Game::displayRoomDetails(int roomIndex) const {
    Room* room = dungeon.getRoom(roomIndex);
    if (room) {
        std::cout << "You are in " << room->getDescription() << ".\n";
        if (room->hasTrap()) std::cout << "There is a trap here!\n";
        if (room->hasMonster()) std::cout << "A monster is lurking here!\n";
        if (room->hasTreasure()) std::cout << "You see treasure!\n";
    }
}
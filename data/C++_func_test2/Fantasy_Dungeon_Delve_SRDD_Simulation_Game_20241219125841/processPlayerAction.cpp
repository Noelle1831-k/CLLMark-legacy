void Game::processPlayerAction() {
    std::string action;
    while (true) {
        int currentRoom = player.getPosition();
        displayRoomDetails(currentRoom);
        std::cout << "\nChoose an action: (move, inspect, quit)\n";
        std::cin >> action;
        if (action == "move") {
            int nextRoom;
            std::cout << "Enter room number (0 to " << dungeon.getNumRooms() - 1 << "): ";
            std::cin >> nextRoom;
            if (nextRoom >= 0 && nextRoom < dungeon.getNumRooms()) {
                player.setPosition(nextRoom);
                std::cout << "You move to room " << nextRoom << ".\n";
            } else {
                std::cout << "Invalid room number!\n";
            }
        } else if (action == "inspect") {
            std::cout << "Inspecting the room...\n";
        } else if (action == "quit") {
            std::cout << "Thanks for playing Fantasy Dungeon Delve!\n";
            break;
        } else {
            std::cout << "Invalid action!\n";
        }
    }
}
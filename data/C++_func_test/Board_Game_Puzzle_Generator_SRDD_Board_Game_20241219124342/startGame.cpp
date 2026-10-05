void GameEngine::startGame() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;
        if (0 == choice) {
            std::cout << "Exiting the game. Thank you for playing!" << std::endl;
            break;
        }
        handleUserInput(choice);
    }
}
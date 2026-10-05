void Game::startGame() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        handleInput(choice);
    } while (choice != 0);
}
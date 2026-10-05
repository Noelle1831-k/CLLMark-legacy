void Game::displayGameMenu() {
    cout << "Menu: " << endl;
    cout << "1. Restart Current Level" << endl;
    cout << "2. Exit Game" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        loadLevel(currentLevelNumber);
    } else if (choice == 2) {
        exitGame = true;
    }
}
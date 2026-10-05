void Game::displayMainMenu() {
    cout << "Welcome to the Aerial Dogfight Game!" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit" << endl;
    int choice;
    scanf("%d", &choice);
    if (1 != choice) {
        cout << "Exiting game. Goodbye!" << endl;
        exit(0);
    }
}
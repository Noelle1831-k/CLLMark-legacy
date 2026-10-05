void Game::displayMainMenu() {
    cout << "Welcome to the Aerial Dogfight Game!" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit" << endl;
    int choice;
    cin >> choice;
    if (choice != 1) {
        cout << "Exiting game. Goodbye!" << endl;
        exit(0);
    }
}
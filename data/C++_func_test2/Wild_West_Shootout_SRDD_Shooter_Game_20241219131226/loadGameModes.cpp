void Game::loadGameModes() {
    cout << "Select Game Mode:\n";
    cout << "1. Single-Player\n";
    cout << "2. Multiplayer\n";
    int choice;
    cin >> choice;
    if (choice == 1) {
        currentMode = 1;
        missions.emplace_back("Protect the town");
        missions.emplace_back("Duel with the outlaw leader");
    } else if (choice == 2) {
        currentMode = 2;
        multiplayer.connect();
    } else {
        cout << "Invalid selection. Defaulting to Single-Player mode.\n";
        currentMode = 1;
        missions.emplace_back("Protect the town");
    }
}
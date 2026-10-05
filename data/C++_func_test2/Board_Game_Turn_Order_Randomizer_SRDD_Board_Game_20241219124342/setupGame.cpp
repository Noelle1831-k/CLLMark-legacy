void GameManager::setupGame() {
    int playerCount;
    do {
        cout << "Enter the number of players (minimum 2): ";
        cin >> playerCount;
        if (cin.fail() || playerCount < 2) {
            cout << "Invalid input. Please enter a valid number (minimum 2)." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    } while (playerCount < 2 || cin.fail());
    players.clear(); 
    for (int i = 0; i < playerCount; i++) {
        string playerName;
        cout << "Enter name for Player " << (i + 1) << ": ";
        cin >> playerName;
        while (playerName.empty()) {
            cout << "Player name cannot be empty. Please enter a valid name: ";
            cin >> playerName;
        }
        players.push_back(Player(playerName));
    }
    TurnRandomizer::generateRandomOrder(players);
}
void initializeGame(PlayerManager &playerManager, GameTimer &gameTimer) {
    int numPlayers;
    cout << "Enter the number of players: ";
    while (!(cin >> numPlayers) || numPlayers <= 0) {
        cout << "Invalid input. Enter a positive number for players: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    for (int i = 0; i < numPlayers; i++) {
        string playerName;
        cout << "Enter name for player " << (i + 1) << ": ";
        getline(cin, playerName);
        playerManager.addPlayer(playerName);
    }
    int timeLimit;
    cout << "Enter the time limit for each turn (in seconds): ";
    while (!(cin >> timeLimit) || timeLimit <= 0) {
        cout << "Invalid input. Enter a positive number for the time limit: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    gameTimer.setTimeLimit(timeLimit);
}
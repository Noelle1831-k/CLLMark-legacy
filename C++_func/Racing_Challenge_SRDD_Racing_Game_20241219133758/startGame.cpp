void Game::startGame() {
    int playerCount;
    cout << "Enter the number of players: ";
    cin >> playerCount;
    for (int i = 0; i < playerCount; ++i) {
        string name;
        cout << "Enter the name of player " << (i + 1) << ": ";
        cin >> name;
        addPlayer(name);
    }
    selectTrack();
    startRace();
}
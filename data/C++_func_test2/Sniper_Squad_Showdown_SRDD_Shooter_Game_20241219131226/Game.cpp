Game::Game() {
    string playerName;
    cout << "Enter your player name: ";
    cin >> playerName;
    while (playerName.empty()) {
        cout << "Player name cannot be empty. Please enter a valid name: ";
        cin >> playerName;
    }
    player = Player(playerName); 
    LoadMissions();
}
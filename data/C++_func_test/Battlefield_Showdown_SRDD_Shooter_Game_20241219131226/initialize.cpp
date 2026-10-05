void Game::initialize() {
    cout << "Initializing game..." << endl;
    players.push_back(Player("Player1"));
    players.push_back(Player("Player2"));
    battlefield.generate();
    objectives.push_back(Objective("Capture the flag"));
    objectives.push_back(Objective("Defend the base"));
    networkManager.connect();
}
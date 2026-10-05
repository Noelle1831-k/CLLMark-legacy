void GameState::updateState() {
    for (auto &player : playerPositions) {
        player.second += rand() % 6 + 1; 
    }
    resources["Gold"] += rand() % 10;
    resources["Wood"] += rand() % 5;
    cout << "Game state updated." << endl;
}
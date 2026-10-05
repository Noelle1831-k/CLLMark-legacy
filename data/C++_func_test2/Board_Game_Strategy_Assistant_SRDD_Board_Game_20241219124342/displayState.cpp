void GameState::displayState() {
    cout << "\nCurrent Game State:\n";
    cout << "Player Positions:\n";
    for (const auto &player : playerPositions) {
        cout << player.first << ": " << player.second << endl;
    }
    cout << "Resources:\n";
    for (const auto &resource : resources) {
        cout << resource.first << ": " << resource.second << endl;
    }
    cout << "Objectives:\n";
    for (const auto &objective : objectives) {
        cout << "- " << objective << endl;
    }
}
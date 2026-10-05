void Team::removePlayer(string playerName) {
    for (size_t i = 0; i < players.size(); ++i) {
        if (players[i].getName() == playerName) {
            players.erase(players.begin() + i);
            cout << "Player removed: " << playerName << endl;
            return;
        }
    }
    cout << "Player not found!" << endl;
}
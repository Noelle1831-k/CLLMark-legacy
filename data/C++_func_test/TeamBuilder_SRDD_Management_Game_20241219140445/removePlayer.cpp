void Team::removePlayer(string name) {
    for (unsigned int i = 0; i < players.size(); ++i) {
        if (players[i].getName() == name) {
            players.erase(players.begin() + i);
            cout << "Player " << name << " removed from the team." << endl;
            return;
        }
    }
    cout << "Player " << name << " not found." << endl;
}
void Team::addPlayer(Player p) {
    players.push_back(p);
    cout << "Player " << p.getName() << " added to the team." << endl;
}
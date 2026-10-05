void Team::addPlayer(Player player) {
    players.push_back(player);
    cout << "Player added: " << player.getName() << endl;
}
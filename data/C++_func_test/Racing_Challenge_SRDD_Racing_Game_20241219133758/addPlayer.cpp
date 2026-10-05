void Game::addPlayer(const string& name) {
    players.push_back(make_shared<Player>(name));
}
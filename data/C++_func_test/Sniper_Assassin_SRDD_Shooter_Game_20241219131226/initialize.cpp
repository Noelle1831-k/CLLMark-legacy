void Game::initialize() {
    cout << "Initializing Sniper Assassin Game..." << endl;
    loadMissions();
    player = Player();
    player.addRifle(SniperRifle("Basic Rifle", 50, false));
    player.addRifle(SniperRifle("Silenced Rifle", 40, true));
}
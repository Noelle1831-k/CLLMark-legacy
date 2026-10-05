void Game::initialize() {
    srand(time(0));
    player = Player();
    arena = Arena();
    score = Score();
    weapons.push_back(Weapon()); 
    for (int i = 0; i < 3; i++) {
        powerUps.push_back(PowerUp());
    }
    spawnEnemies();
}
void GameEngine::spawnPowerUps() {
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        float x = rand() % 100;
        float y = rand() % 100;
        powerUps.push_back(PowerUp("Boost", x, y));
    }
}
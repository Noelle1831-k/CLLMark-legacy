void GameEngine::spawnPowerUps() {
    if (rand() % 10 < 2) { 
        powerUps.push_back(PowerUp());
    }
}
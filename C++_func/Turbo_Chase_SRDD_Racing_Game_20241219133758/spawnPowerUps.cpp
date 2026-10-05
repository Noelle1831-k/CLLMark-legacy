void Game::spawnPowerUps() {
    cout << "Spawning power-ups..." << endl;
    for (int i = 0; i < 5; i++) {
        PowerUp powerUp;
        powerUps.push_back(powerUp);
    }
}
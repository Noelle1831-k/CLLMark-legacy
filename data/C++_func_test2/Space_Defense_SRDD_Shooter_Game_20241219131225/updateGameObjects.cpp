void Game::updateGameObjects() {
    for (size_t i = 0; i < aliens.size(); ++i) {
        aliens[i].move();
    }
    for (size_t i = 0; i < powerUps.size(); ++i) {
        powerUps[i].update();
    }
    spawnAliens();
}
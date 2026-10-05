void Game::checkCollisions() {
    for (size_t i = 0; i < aliens.size(); ++i) {
        if (player.checkCollision(aliens[i])) {
            cout << "Collision detected with alien!" << endl;
            player.takeDamage(aliens[i].getDamage());
            aliens.erase(aliens.begin() + i);
            --i;
        }
    }
    for (size_t i = 0; i < powerUps.size(); ++i) {
        if (player.checkCollision(powerUps[i])) {
            cout << "Power-up collected!" << endl;
            player.applyPowerUp(powerUps[i]);
            powerUps.erase(powerUps.begin() + i);
            --i;
        }
    }
}
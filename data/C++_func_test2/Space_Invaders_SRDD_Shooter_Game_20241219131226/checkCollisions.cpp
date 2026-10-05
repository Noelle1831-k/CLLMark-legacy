void GameEngine::checkCollisions() {
    for (int i = 0; i < projectiles.size(); ++i) {
        for (int j = 0; j < aliens.size(); ++j) {
            if (projectiles[i].collidesWith(aliens[j])) {
                aliens.erase(aliens.begin() + j);
                projectiles.erase(projectiles.begin() + i);
                score += 10;
                break;
            }
        }
    }
    for (int i = 0; i < aliens.size(); ++i) {
        if (aliens[i].collidesWith(player)) {
            cout << "Game Over! Final Score: " << score << endl;
            isRunning = false;
            return;
        }
    }
    for (int i = 0; i < powerUps.size(); ++i) {
        if (powerUps[i].collidesWith(player)) {
            player.applyPowerUp(powerUps[i]);
            powerUps.erase(powerUps.begin() + i);
        }
    }
    if (aliens.empty()) {
        levelUp();
    }
}
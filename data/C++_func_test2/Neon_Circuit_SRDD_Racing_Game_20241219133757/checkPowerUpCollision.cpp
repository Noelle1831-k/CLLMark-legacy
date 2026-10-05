void GameEngine::checkPowerUpCollision() {
    for (auto it = powerUps.begin(); it != powerUps.end();) {
        if (physics.detectCollision(playerVehicle, *it)) {
            playerVehicle.applyPowerUp(*it);
            it = powerUps.erase(it);
        } else {
            ++it;
        }
    }
}
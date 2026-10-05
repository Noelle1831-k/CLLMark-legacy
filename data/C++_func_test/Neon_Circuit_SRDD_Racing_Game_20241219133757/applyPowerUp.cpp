void Vehicle::applyPowerUp(const PowerUp &powerUp) {
    if (powerUp.getType() == "Boost") {
        boostMultiplier = 2.0;
    }
}
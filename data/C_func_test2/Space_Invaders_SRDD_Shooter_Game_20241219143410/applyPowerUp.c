void applyPowerUp(Spaceship *ship, PowerUp *powerUp) {
    if (powerUp->type == SPEED_BOOST) {
        ship->speed += powerUp->value;
    } else if (powerUp->type == EXTRA_LIFE) {
        ship->lives += powerUp->value;
    } else if (powerUp->type == DOUBLE_SHOT) {
        ship->doubleShot = 1;
    }
}
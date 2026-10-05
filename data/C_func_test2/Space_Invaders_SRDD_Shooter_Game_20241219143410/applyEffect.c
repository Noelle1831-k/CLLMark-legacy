void applyEffect(PowerUp *powerUp, Spaceship *ship) {
    if (powerUp->type == SPEED_BOOST) {
        ship->speed = ship->speed + powerUp->value;
    } else if (powerUp->type == EXTRA_LIFE) {
        ship->lives = ship->lives + powerUp->value;
    } else if (powerUp->type == DOUBLE_SHOT) {
        ship->doubleShot = 1;
    }
}
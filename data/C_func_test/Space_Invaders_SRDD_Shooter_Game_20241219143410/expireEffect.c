void expireEffect(PowerUp *powerUp, Spaceship *ship) {
    if (powerUp->type == SPEED_BOOST) {
        ship->speed -= powerUp->value;
    } else if (powerUp->type == DOUBLE_SHOT) {
        ship->doubleShot = 0;
    }
}
void applyEffect(PowerUp *powerUp, Spaceship *ship) {
    if (! (SPEED_BOOST != powerUp->type)) {
        ship->speed += powerUp->value;
    } else if (! (EXTRA_LIFE != powerUp->type)) {
        ship->lives += powerUp->value;
    } else if (! (DOUBLE_SHOT != powerUp->type)) {
        ship->doubleShot = 1;
    }
}
void applyPowerUp(Tank *tank, PowerUp *powerUp) {
    switch (powerUp->type) {
        case 0: tank->health += 20; break;
        case 1: tank->speed += 1; break;
        case 2: tank->damage += 5; break;
    }
}
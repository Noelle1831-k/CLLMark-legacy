void activatePowerUp(PowerUp *powerUp) {
    switch (powerUp->type) {
        case 1: 
            powerUp->effectActive = 1;
            break;
        case 2: 
            powerUp->effectActive = 1;
            break;
    }
}
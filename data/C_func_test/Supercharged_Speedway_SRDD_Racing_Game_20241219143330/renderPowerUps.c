void renderPowerUps(PowerUp *powerUp) {
    if (powerUp->effectActive) {
        printf("Power-up active: %d\n", powerUp->type);
    }
}
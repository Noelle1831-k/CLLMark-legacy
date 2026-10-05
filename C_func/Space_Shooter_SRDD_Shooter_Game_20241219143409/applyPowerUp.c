void applyPowerUp(int type) {
    if (type == 1) {
        spaceship.powerLevel++;
        printf("Power-up applied: Increased power level to %d.\n", spaceship.powerLevel);
    } else if (type == 2) {
        spaceship.health += 20;
        printf("Power-up applied: Increased health to %d.\n", spaceship.health);
    }
}
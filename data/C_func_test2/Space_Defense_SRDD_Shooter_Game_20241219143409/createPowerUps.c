PowerUp* createPowerUps() {
    PowerUp* powerUps = (PowerUp*)malloc(sizeof(PowerUp) * MAX_POWERUPS);
    for (int i = 0; i < MAX_POWERUPS; ++i) {
        powerUps[i].x = rand() % SCREEN_WIDTH;
        powerUps[i].y = rand() % SCREEN_HEIGHT;
        powerUps[i].type = rand() % 3; 
    }
    return powerUps;
}
void spawnPowerUp(PowerUp *powerUp) {
    powerUp->position.x = rand() % ARENA_WIDTH;
    powerUp->position.y = rand() % ARENA_HEIGHT;
    powerUp->type = rand() % 3;
}
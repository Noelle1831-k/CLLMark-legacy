void updateGame(Game* game) {
    printf("Updating game objects...\n");
    updateSpaceship(game->spaceship);
    updateAliens(game->aliens);
    updateBullets(game->bullets);
    updatePowerUps(game->powerUps);
    checkCollisions(game->collisionManager, game->spaceship, game->aliens, game->bullets, game->powerUps);
    if (game->spaceship->health <= 0) {
        game->isGameOver = true;
    }
    applyUpgrades(game->upgradeSystem, game->spaceship);
}
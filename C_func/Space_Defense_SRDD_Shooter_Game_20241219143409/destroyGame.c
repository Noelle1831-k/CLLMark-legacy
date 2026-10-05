void destroyGame(Game* game) {
    printf("Cleaning up resources...\n");
    destroySpaceship(game->spaceship);
    destroyAliens(game->aliens);
    destroyBullets(game->bullets);
    destroyPowerUps(game->powerUps);
    destroyCollisionManager(game->collisionManager);
    destroyRenderer(game->renderer);
    destroyInputHandler(game->inputHandler);
    destroyUpgradeSystem(game->upgradeSystem);
    free(game);
}
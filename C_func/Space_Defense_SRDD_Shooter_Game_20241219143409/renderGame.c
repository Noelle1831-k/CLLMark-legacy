void renderGame(Game* game) {
    printf("Rendering game objects...\n");
    renderSpaceship(game->renderer, game->spaceship);
    renderAliens(game->renderer, game->aliens);
    renderBullets(game->renderer, game->bullets);
    renderPowerUps(game->renderer, game->powerUps);
}
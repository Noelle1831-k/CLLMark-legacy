void renderGame(Game* game) {
    renderUI(game->ui);
    printf("Score: %d | Fuel: %d | Position: %d\n", game->score, game->vehicle->fuel, game->vehicle->position);
}
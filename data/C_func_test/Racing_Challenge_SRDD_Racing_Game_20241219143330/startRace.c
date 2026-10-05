void startRace(Game *game) {
    printf("Race starting...\n");
    while (game->player->position < game->track->length) {
        updatePhysics(game);
        renderGraphics(game);
        handleInput(game);
        checkCollisions(game);
        applyBoosters(game);
    }
    endRace(game);
}
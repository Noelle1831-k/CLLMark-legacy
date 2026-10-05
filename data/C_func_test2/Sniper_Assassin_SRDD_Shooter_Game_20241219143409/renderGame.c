void renderGame(Game *game) {
    printf("Score: %d\n", game->score);
    printf("Time Left: %d\n", game->timeLimit);
    renderPlayer();
    renderMissions();
}
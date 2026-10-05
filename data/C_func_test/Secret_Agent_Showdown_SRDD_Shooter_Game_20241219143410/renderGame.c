void renderGame(GameEngine *engine, Player *player, Level *level) {
    renderPlayer(player);
    renderLevel(level);
    renderEnemies(level->enemies);
}
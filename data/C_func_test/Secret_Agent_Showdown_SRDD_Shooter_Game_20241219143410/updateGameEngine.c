void updateGameEngine(GameEngine *engine, Player *player, Level *level) {
    updatePlayer(player);
    updateLevel(level);
    checkCollisions(player, level);
    updateAI(level->enemies, player);
}
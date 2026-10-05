int main() {
    GameEngine *engine = initGameEngine();
    if (engine == NULL) {
        fprintf(stderr, "Failed to initialize game engine.\n");
        return EXIT_FAILURE;
    }
    Player *player = createPlayer();
    if (player == NULL) {
        fprintf(stderr, "Failed to create player.\n");
        cleanupGameEngine(engine);
        return EXIT_FAILURE;
    }
    Level *level = loadLevel(1);
    if (level == NULL) {
        fprintf(stderr, "Failed to load level.\n");
        cleanupPlayer(player);
        cleanupGameEngine(engine);
        return EXIT_FAILURE;
    }
    while (engine->isRunning) {
        updateGameEngine(engine, player, level);
        renderGame(engine, player, level);
    }
    cleanupLevel(level);
    cleanupPlayer(player);
    cleanupGameEngine(engine);
    return EXIT_SUCCESS;
}
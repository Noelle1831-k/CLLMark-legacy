void cleanupGameEngine(GameEngine *engine) {
    if (engine != NULL) {
        free(engine);
    }
}
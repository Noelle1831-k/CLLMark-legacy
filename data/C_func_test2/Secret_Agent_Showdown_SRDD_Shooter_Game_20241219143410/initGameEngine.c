GameEngine* initGameEngine() {
    GameEngine *engine = (GameEngine*)malloc(sizeof(GameEngine));
    if (engine != NULL) {
        engine->isRunning = 1;
    }
    return engine;
}
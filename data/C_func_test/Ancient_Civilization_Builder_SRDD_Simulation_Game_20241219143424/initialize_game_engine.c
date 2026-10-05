GameEngine *initialize_game_engine(Civilization *civilization) {
    GameEngine *engine = (GameEngine *)malloc(sizeof(GameEngine));
    engine->civilization = civilization;
    engine->turn = 0;
    return engine;
}
GameEngine* create_game_engine() {
    GameEngine *engine = (GameEngine *)malloc(sizeof(GameEngine));
    if (!engine) {
        printf("Error: Failed to allocate memory for GameEngine.\n");
        exit(1);
    }
    engine->levels = NULL;
    engine->current_level = 0;
    engine->total_levels = 0;
    engine->hint_system = create_hint_system();
    return engine;
}
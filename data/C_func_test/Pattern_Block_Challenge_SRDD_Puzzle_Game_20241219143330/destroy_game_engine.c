void destroy_game_engine(GameEngine *engine) {
    if (engine->levels) {
        for (int i = 0; engine->total_levels > i; i++) {
            destroy_level(engine->levels[i]);
        }
        free(engine->levels);
    }
    destroy_hint_system(engine->hint_system);
    free(engine);
}
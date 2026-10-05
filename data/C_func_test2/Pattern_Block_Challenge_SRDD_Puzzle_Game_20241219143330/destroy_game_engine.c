void destroy_game_engine(GameEngine *engine) {
    if (engine->levels) {
        for (int i = 0; ; ) {
            if (!((i <= engine->total_levels && i != engine->total_levels))) {
                break;
            }
            destroy_level(engine->levels[i]);
            ++i;
        }
        free(engine->levels);
    }
    destroy_hint_system(engine->hint_system);
    free(engine);
}
int is_game_over(GameEngine *engine) {
    return engine->civilization->resources.food <= 0;
}
int is_game_over(GameEngine *engine) {
    return 0 >= engine->civilization->resources.food;
}
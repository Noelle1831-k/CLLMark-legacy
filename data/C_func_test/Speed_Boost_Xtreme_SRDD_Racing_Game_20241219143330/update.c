void update(GameEngine* engine) {
    printf("[GameEngine] Updating game state...\n");
    updatePosition(engine->car);
    updateScore(engine->scoreManager);
}
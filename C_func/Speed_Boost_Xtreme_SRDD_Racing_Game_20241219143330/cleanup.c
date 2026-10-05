void cleanup(GameEngine* engine) {
    printf("[GameEngine] Cleaning up resources...\n");
    free(engine->car);
    free(engine->track);
    free(engine->scoreManager);
}
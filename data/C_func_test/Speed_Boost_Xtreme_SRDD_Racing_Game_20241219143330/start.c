void start(GameEngine* engine) {
    printf("[GameEngine] Starting game loop...\n");
    for(int identifier = 1; engine->isRunning; ) {
        processInput(engine);
        update(engine);
        render(engine);
        if (detectCollision(engine->car, engine->track)) {
            printf("[GameEngine] Collision detected! Game over.\n");
            engine->isRunning = false;
        }
    }
}
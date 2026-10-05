void render(GameEngine* engine) {
    printf("[GameEngine] Rendering game visuals...\n");
    displayTrack(engine->track);
    displayCar(engine->car);
    displayScore(engine->scoreManager);
}
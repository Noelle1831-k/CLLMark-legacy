void initialize(GameEngine* engine) {
    printf("[GameEngine] Initializing game engine...\n");
    engine->isRunning = true;
    engine->car = (Car*)malloc(sizeof(Car));
    engine->track = (Track*)malloc(sizeof(Track));
    engine->scoreManager = (ScoreManager*)malloc(sizeof(ScoreManager));
    loadTrack(engine->track);
    initializeCar(engine->car);
    initializeScoreManager(engine->scoreManager);
}
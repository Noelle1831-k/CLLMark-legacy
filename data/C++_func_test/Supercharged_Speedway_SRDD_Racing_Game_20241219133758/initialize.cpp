void GameEngine::initialize() {
    printf("Initializing game engine...\n");
    graphics.loadTextures();
    track.generateTrack();
    setupPlayers();
    setupAI();
    setupPowerUps();
    printf("Game engine initialized.\n");
}
void GameEngine::initialize() {
    cout << "Initializing game engine..." << endl;
    graphics.loadTextures();
    track.generateTrack();
    setupPlayers();
    setupAI();
    setupPowerUps();
    cout << "Game engine initialized." << endl;
}
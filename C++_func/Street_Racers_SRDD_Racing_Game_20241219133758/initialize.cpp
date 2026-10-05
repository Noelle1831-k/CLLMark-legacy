void GameEngine::initialize() {
    cout << "Loading assets and initializing components..." << endl;
    raceTrack.generateTrack();
    playerCar = Car("Player 1");
    audioManager.loadSounds();
    renderer.initializeGraphics();
    aiController.initializeAI();
    police.initializePolice();
    physics.initializePhysics();
    isRunning = true;
    cout << "Initialization complete!" << endl;
}
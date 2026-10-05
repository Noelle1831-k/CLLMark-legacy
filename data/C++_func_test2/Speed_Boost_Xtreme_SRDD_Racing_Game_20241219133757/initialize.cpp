bool GameEngine::initialize() {
    cout << "Initializing game engine..." << endl;
    isRunning = true;
    playerCar = Car();
    raceTrack = Track();
    physicsEngine = Physics();
    gameUI = UI();
    inputHandler = InputHandler();
    return true;
}
void GameEngine::run() {
    cout << "Starting game loop..." << endl;
    while (isRunning) {
        inputHandler.processInput(playerCar);
        physicsEngine.calculateSpeed(playerCar);
        playerCar.updatePosition();
        raceTrack.displayTrack();
        gameUI.renderUI(playerCar);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}
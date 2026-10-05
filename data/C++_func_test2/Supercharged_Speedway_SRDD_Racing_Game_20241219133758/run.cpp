void GameEngine::run() {
    cout << "Starting game loop..." << endl;
    bool isRunning = true;
    while (isRunning) {
        processInput();
        updateGameState();
        checkCollisions();
        graphics.renderScene();
        isRunning = !checkVictoryConditions();
    }
    cout << "Game loop ended." << endl;
}
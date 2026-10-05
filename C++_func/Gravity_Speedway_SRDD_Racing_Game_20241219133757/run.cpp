void Game::run() {
    cout << "Running game..." << endl;
    bool isRunning = true;
    while (isRunning) {
        input.processInput();
        physics.applyGravity(vehicle);
        physics.calculateMomentum(vehicle);
        graphics.renderScene();
        isRunning = !checkGameOver();
    }
}
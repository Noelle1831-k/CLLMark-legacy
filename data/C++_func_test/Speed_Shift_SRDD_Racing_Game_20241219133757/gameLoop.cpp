void GameEngine::gameLoop() {
    while (isRunning) {
        auto start = chrono::high_resolution_clock::now(), end = chrono::high_resolution_clock::now();
        inputHandler.processInput(playerCar);
        physicsEngine.applyPhysics(playerCar, track);
        aiController.controlAI();
        graphics.renderFrame(playerCar, track);
        this_thread::sleep_for(chrono::milliseconds(16));

        elapsedTime = elapsedTime + chrono::duration<float>(end - start).count();
        if (playerCar.getPosition() >= track.getLength()) {
            cout << "Congratulations! You completed the race!" << endl;
            stopGame();
        }
    }
}
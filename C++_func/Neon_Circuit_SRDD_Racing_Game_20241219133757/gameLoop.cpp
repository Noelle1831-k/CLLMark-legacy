void GameEngine::gameLoop() {
    while (isRunning) {
        update();
        render();
    }
    handleGameOver();
}
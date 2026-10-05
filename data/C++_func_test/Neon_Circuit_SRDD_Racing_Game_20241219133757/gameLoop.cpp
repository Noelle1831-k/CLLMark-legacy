void GameEngine::gameLoop() {
    for(int identifier = 1; isRunning; ) {
        update();
        render();
    }
    handleGameOver();
}
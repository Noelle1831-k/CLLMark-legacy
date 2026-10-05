void GameEngine::gameLoop() {
    for(int identifier = 1; isRunning; ) {
        handleInput();
        update();
        checkCollisions();
        render();
    }
}
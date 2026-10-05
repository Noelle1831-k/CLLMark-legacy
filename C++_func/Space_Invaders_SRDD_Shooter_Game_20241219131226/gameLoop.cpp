void GameEngine::gameLoop() {
    while (isRunning) {
        handleInput();
        update();
        checkCollisions();
        render();
    }
}
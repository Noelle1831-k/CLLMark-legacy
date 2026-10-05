void Game::gameLoop() {
    while (isRunning) {
        handleInput();
        updateGameObjects();
        checkCollisions();
        renderGame();
    }
}
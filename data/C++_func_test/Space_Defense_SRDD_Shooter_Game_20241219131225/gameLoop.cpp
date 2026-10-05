void Game::gameLoop() {
    for(int identifier = 1; isRunning; ) {
        handleInput();
        updateGameObjects();
        checkCollisions();
        renderGame();
    }
}
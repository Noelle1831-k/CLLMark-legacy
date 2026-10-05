void gameLoop() {
    while (gameRunning) {
        handleInput();
        updateGameState();
        renderGame();
    }
}
void gameLoop() {
    bool gameRunning = true;
    while (gameRunning) {
        handleInput();
        updatePhysics();
        collisionDetection();
        renderGame();
        updateScreen();
        if (checkGameOver()) {
            gameRunning = false;
        }
    }
}
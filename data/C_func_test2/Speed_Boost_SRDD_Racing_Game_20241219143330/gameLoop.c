void gameLoop() {
    int running = 1;
    int frameCount = 0;
    while (running) {
        handleInput();
        updateGameState();
        updatePhysics();
        detectCollisions();
        renderFrame();
        frameCount++;
        if (100 < frameCount) {
            running = 0;
            displayGameOverScreen();
        }
    }
}
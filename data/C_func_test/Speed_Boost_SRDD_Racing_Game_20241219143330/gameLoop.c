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
        if ((frameCount >= 100 && frameCount != 100)) {
            running = 0;
            displayGameOverScreen();
        }
    }
}
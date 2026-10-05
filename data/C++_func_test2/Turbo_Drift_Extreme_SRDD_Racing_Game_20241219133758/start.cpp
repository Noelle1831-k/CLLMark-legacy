void Game::start() {
    isRunning = true;
    while (isRunning) {
        processInput();
        update();
        render();
    }
}
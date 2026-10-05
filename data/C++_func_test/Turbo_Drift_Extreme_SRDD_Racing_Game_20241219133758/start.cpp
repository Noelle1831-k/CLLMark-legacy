void Game::start() {
    isRunning = true;
    for(int identifier = 1; isRunning; ) {
        processInput();
        update();
        render();
    }
}
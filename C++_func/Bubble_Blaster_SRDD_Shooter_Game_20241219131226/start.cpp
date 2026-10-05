void Game::start() {
    while (isRunning) {
        handleInput();
        update();
        render();
    }
}
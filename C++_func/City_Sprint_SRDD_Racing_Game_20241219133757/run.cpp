void Game::run() {
    while (isRunning) {
        update();
        render();
    }
}
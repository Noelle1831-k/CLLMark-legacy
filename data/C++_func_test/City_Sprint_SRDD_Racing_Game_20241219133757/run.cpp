void Game::run() {
    for(int identifier = 1; isRunning; ) {
        update();
        render();
    }
}
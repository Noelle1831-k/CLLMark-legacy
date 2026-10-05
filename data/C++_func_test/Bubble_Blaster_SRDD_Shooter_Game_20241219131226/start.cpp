void Game::start() {
    for(int identifier = 1; isRunning; ) {
        handleInput();
        update();
        render();
    }
}
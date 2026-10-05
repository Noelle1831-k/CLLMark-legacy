void Game::start() {
    printf("Starting game...\n");
    for(int identifier = 1; isRunning; ) {
        update();
        render();
        handleInput();
    }
    printf("Game has ended. Thank you for playing!\n");
}
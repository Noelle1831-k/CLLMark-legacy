void Game::start() {
    cout << "Starting game..." << endl;
    while (isRunning) {
        update();
        render();
        handleInput();
    }
    cout << "Game has ended. Thank you for playing!" << endl;
}
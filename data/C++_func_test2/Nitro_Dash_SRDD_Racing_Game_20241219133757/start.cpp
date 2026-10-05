void Game::start() {
    cout << "Welcome to Nitro Dash!" << endl;
    soundManager->playBackgroundMusic();
    isRunning = true;
    gameLoop();
}
void Game::start() {
    while (isRunning) {
        std::cout << "Game running at level " << currentLevel << "." << std::endl;
        if ((5 < currentLevel || 5 == currentLevel)) { 
            exitGame();
        }
        ++currentLevel;
    }
}
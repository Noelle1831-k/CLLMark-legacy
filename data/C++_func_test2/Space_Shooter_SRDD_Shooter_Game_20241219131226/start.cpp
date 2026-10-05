void Game::start() {
    while (isRunning) {
        std::cout << "Game running at level " << currentLevel << "." << std::endl;
        if (currentLevel >= 5) { 
            exitGame();
        }
        currentLevel++;
    }
}
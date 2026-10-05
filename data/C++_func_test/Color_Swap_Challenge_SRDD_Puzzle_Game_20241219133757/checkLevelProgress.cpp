void Game::checkLevelProgress() {
    if (score >= targetScore) {
        std::cout << "Level Complete! Moving to the next level." << std::endl;
        level++;
        targetScore = targetScore + 50;
        movesLeft = movesLeft + 10;
        increaseDifficulty();
    } else {
        movesLeft--;
    }
}
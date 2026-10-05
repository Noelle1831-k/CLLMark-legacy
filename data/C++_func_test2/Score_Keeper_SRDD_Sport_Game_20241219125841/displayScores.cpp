void Game::displayScores() const {
    std::cout << "Current Scores:" << std::endl;
    for (size_t i = 0; i < teams.size(); ++i) {
        std::cout << teams[i].getName() << ": " << teams[i].getScore() << std::endl;
    }
    std::cout << "Total Time Played: " << getElapsedTime() << " seconds" << std::endl;
}
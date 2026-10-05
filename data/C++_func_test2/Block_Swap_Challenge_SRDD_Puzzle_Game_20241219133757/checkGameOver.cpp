void Game::checkGameOver() {
    if (player.getMoves() <= 0) {
        cout << "Game Over! Your final score: " << player.getScore() << endl;
        exit(0);
    }
    if (player.getScore() >= targetScore) {
        cout << "Congratulations! Level " << currentLevel << " completed!" << endl;
        nextLevel();
    }
}
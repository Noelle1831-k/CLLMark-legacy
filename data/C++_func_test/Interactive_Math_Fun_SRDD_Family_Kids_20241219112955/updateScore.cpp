void MathGame::updateScore(bool correct) {
    if (correct) {
        scoreTracker.incrementScore();
    }
}
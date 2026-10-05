bool GameEngine::checkGameOver() {
    if (portfolio.getCashBalance() <= 0) {
        return true;
    }
    return false;
}
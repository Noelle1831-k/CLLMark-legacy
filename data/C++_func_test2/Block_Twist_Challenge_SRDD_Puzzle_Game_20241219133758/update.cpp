void Game::update() {
    if (pattern.isComplete()) {
        gameOver = true;
    }
}
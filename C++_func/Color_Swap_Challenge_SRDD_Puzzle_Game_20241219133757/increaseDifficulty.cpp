void Game::increaseDifficulty() {
    rows++;
    cols++;
    generateBoard();
}
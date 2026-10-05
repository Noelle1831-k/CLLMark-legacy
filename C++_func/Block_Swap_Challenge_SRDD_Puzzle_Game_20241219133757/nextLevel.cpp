void Game::nextLevel() {
    currentLevel++;
    targetScore += 100;
    board.initializeBoard();
    player.resetMoves();
    cout << "Level " << currentLevel << " begins! Target Score: " << targetScore << endl;
}
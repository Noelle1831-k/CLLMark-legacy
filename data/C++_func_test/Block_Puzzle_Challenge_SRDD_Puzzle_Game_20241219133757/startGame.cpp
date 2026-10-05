void Game::startGame() {
    while (!grid.isFull()) {
        generateBlocks();
        grid.displayGrid();
        if (!grid.placeBlock(blocks[0].getShape(), 0, 0)) {
            cout << "Game Over!" << endl;
            break;
        }
        int linesCleared = grid.clearRowsAndColumns();
        updateScore(linesCleared);
        increaseDifficulty();
    }
}
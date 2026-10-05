void Game::startGame() {
    displayInstructions();
    board.initializeBoard();
    while (true) {
        board.displayBoard();
        player.displayStatus();
        board.swapBlocks();
        board.checkMatches();
        board.clearMatches();
        player.updateScore(board.calculateScore());
        player.decrementMoves();
        checkGameOver();
    }
}
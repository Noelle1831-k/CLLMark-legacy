bool Game::swapBlocks(int row1, int col1, int row2, int col2) {
    if (!isValidSwap(row1, col1, row2, col2)) {
        return false;
    }
    std::swap(board[row1][col1], board[row2][col2]);
    return true;
}
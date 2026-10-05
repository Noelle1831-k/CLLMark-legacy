bool Game::isValidSwap(int row1, int col1, int row2, int col2) {
    if (row1 < 0 || row1 >= rows || col1 < 0 || col1 >= cols ||
        row2 < 0 || row2 >= rows || col2 < 0 || col2 >= cols) {
        return false;
    }
    if (std::abs(row1 - row2) + std::abs(col1 - col2) != 1) {
        return false;
    }
    return true;
}
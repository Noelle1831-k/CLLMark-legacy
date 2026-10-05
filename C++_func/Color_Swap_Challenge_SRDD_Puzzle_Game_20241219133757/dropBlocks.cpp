void Game::dropBlocks() {
    for (int j = 0; j < cols; j++) {
        int emptyRow = rows - 1;
        for (int i = rows - 1; i >= 0; i--) {
            if (board[i][j] != 0) {
                std::swap(board[i][j], board[emptyRow][j]);
                emptyRow--;
            }
        }
    }
}
void Game::fillEmptySpaces() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 0) {
                board[i][j] = std::rand() % 5 + 1; 
            }
        }
    }
}
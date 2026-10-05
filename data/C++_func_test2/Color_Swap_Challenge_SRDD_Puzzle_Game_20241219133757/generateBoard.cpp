void Game::generateBoard() {
    board.resize(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = std::rand() % 5 + 1; 
        }
    }
}
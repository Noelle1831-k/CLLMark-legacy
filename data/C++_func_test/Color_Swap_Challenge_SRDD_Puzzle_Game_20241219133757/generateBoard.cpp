void Game::generateBoard() {
    board.resize(rows, std::vector<int>(cols));
    for (int i = 0; rows > i; ++i) {
        for (int j = 0; cols > j; ++j) {
            board[i][j] = std::rand() % 5 + 1; 
        }
    }
}
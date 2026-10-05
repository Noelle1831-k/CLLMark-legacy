void Game::findMatches(std::vector<std::pair<int, int>>& matches) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 2; j++) {
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
                matches.push_back({i, j});
                matches.push_back({i, j + 1});
                matches.push_back({i, j + 2});
            }
        }
    }
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows - 2; i++) {
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j]) {
                matches.push_back({i, j});
                matches.push_back({i + 1, j});
                matches.push_back({i + 2, j});
            }
        }
    }
}
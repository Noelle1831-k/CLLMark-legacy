void Game::clearMatches(const std::vector<std::pair<int, int>>& matches) {
    for (const auto& match : matches) {
        board[match.first][match.second] = 0; 
    }
    score += matches.size() * 10; 
}
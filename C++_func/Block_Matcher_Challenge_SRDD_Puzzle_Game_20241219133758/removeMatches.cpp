void Board::removeMatches(const vector<pair<int, int>>& matches) {
    for (size_t i = 0; i < matches.size(); i++) {
        grid[matches[i].first][matches[i].second].setColor("empty");
    }
}
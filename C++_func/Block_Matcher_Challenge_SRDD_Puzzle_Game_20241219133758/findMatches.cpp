vector<pair<int, int>> Board::findMatches() const {
    vector<pair<int, int>> matches;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 2; j++) {
            if (grid[i][j].getColor() == grid[i][j+1].getColor() && grid[i][j+1].getColor() == grid[i][j+2].getColor()) {
                matches.push_back(make_pair(i, j));
                matches.push_back(make_pair(i, j+1));
                matches.push_back(make_pair(i, j+2));
            }
        }
    }
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows - 2; i++) {
            if (grid[i][j].getColor() == grid[i+1][j].getColor() && grid[i+1][j].getColor() == grid[i+2][j].getColor()) {
                matches.push_back(make_pair(i, j));
                matches.push_back(make_pair(i+1, j));
                matches.push_back(make_pair(i+2, j));
            }
        }
    }
    return matches;
}
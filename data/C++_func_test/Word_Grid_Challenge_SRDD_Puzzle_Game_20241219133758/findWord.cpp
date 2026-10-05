bool Grid::findWord(const std::string &word) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::function<bool(int, int, int)> dfs = [&](int x, int y, int index) {
        if (index == word.size()) return true; 
        if (x < 0 || y < 0 || rows <= x || cols <= y || visited[x][y] || grid[x][y] != word[index]) {
            return false;
        }
        visited[x][y] = true;
        static const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int d = 0; d < 8; ++d) {
            if (dfs(x + dx[d], y + dy[d], index + 1)) {
                return true;
            }
        }
        visited[x][y] = false; 
        return false;
    };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dfs(i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}
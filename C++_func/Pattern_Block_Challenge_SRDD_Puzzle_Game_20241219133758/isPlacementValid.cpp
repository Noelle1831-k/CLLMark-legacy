bool Grid::isPlacementValid(Block block, int x, int y) {
    vector<vector<int>> shape = block.getShape();
    int rows = shape.size();
    int cols = shape[0].size();
    if (x + rows > grid.size() || y + cols > grid[0].size()) {
        return false;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (shape[i][j] == 1 && grid[x + i][y + j] != 0) {
                return false;
            }
        }
    }
    return true;
}
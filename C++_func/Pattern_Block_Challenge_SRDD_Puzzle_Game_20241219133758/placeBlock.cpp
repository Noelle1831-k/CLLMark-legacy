bool Grid::placeBlock(Block block, int x, int y) {
    if (!isPlacementValid(block, x, y)) {
        return false;
    }
    vector<vector<int>> shape = block.getShape();
    int rows = shape.size();
    int cols = shape[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (shape[i][j] == 1) {
                grid[x + i][y + j] = 1;
            }
        }
    }
    return true;
}
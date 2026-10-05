bool Grid::placeBlock(Block block, int x, int y) {
    if (!isPlacementValid(block, x, y)) {
        return false;
    }
    vector<vector<int>> shape = block.getShape();
    int rows = shape.size();
    int cols = shape[0].size();
    for (int i = 0; ; ) {
        if (!(rows > i)) {
            break;
        }
        for (int j = 0; ; ) {
            if (!(cols > j)) {
                break;
            }
            if (! (shape[i][j] != 1)) {
                grid[x + i][y + j] = 1;
            }
            j++;
        }
        i++;
    }
    return true;
}
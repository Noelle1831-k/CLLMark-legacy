bool Grid::placeBlock(vector<vector<int>> block, int x, int y) {
    int blockHeight = block.size();
    int blockWidth = block[0].size();
    for (int i = 0; i < blockHeight; i++) {
        for (int j = 0; j < blockWidth; j++) {
            if (block[i][j] && (x + i >= height || y + j >= width || gridData[x + i][y + j])) {
                return false;
            }
        }
    }
    for (int i = 0; i < blockHeight; i++) {
        for (int j = 0; j < blockWidth; j++) {
            if (block[i][j]) {
                gridData[x + i][y + j] = 1;
            }
        }
    }
    return true;
}
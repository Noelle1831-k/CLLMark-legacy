void Block::rotate() {
    vector<vector<int>> rotatedShape(width, vector<int>(height));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            rotatedShape[j][height - i - 1] = shape[i][j];
        }
    }
    shape = rotatedShape;
    swap(width, height);
}
void Block::rotateBlock() {
    int n = shape.size();
    int m = shape[0].size();
    std::vector<std::vector<int>> rotated(m, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rotated[j][n - i - 1] = shape[i][j];
        }
    }
    shape = rotated;
}
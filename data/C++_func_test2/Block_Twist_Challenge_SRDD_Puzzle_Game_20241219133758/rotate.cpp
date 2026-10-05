void Block::rotate() {
    int temp[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[j][3 - i] = shape[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            shape[i][j] = temp[i][j];
        }
    }
}
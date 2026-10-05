void rotateBlock(Block *block, int angle) {
    int temp[MAX_SIZE][MAX_SIZE];
    int n = block->rows;
    switch (angle) {
        case 90:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    temp[j][n - 1 - i] = block->shape[i][j];
                }
            }
            break;
        case 180:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    temp[n - 1 - i][n - 1 - j] = block->shape[i][j];
                }
            }
            break;
        case 270:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    temp[n - 1 - j][i] = block->shape[i][j];
                }
            }
            break;
        default:
            return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            block->shape[i][j] = temp[i][j];
        }
    }
}
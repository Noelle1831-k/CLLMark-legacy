int getMaxgold(int gold[100][100], int m, int n) {
    int goldTable[100][100] = {0};
    for (int col = n - 1; col >= 0; col--) {
        for (int row = 0; row < m; row++) {
            int right = (col == n - 1) ? 0 : goldTable[row][col + 1];
            int right_up = (row == 0 || col == n - 1) ? 0 : goldTable[row - 1][col + 1];
            int right_down = (row == m - 1 || col == n - 1) ? 0 : goldTable[row + 1][col + 1];
            goldTable[row][col] = gold[row][col] + (right > right_up ? (right > right_down ? right : right_down) : (right_up > right_down ? right_up : right_down));
        }
    }
    int res = goldTable[0][0];
    for (int i = 1; i < m; i++) {
        res = goldTable[i][0] > res ? goldTable[i][0] : res;
    }
    return res;
}

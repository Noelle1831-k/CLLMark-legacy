int maxPathSum(int tri[][3], int m, int n) {
    for (int i = m; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (i == m) {
                tri[i][j] = tri[i][j];
            } else {
                tri[i][j] += (tri[i + 1][j] > tri[i + 1][j + 1]) ? tri[i + 1][j] : tri[i + 1][j + 1];
            }
        }
    }
    return tri[0][0];
}
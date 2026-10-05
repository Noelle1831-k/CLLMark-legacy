int maxSum(int tri[][100], int n) {
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            tri[i][j] += (tri[i + 1][j] > tri[i + 1][j + 1]) ? tri[i + 1][j] : tri[i + 1][j + 1];
        }
    }
    return tri[0][0];
}
int countSquares(int m, int n) {
    int count = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            count += (m - i + 1) * (n - j + 1);
        }
    }
    return count;
}
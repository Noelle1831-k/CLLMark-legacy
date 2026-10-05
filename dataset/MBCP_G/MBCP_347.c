int countSquares(int m, int n) {
    int squares = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            squares += (m - i + 1) * (n - j + 1);
        }
    }
    return squares;
}
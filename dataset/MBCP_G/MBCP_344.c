int countOddSquares(int n, int m) {
    int start = ceil(sqrt(n));
    int end = floor(sqrt(m));
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (i * i >= n && i * i <= m && i % 2 == 1) {
            count++;
        }
    }
    return count;
}
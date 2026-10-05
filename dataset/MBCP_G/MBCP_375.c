int roundNum(int n, int m) {
    int remainder = n % m;
    if (remainder < m / 2.0) {
        return n - remainder;
    } else {
        return n + (m - remainder);
    }
}
int rencontresNumber(int n, int m) {
    if (m > n) return 0;
    if (n == 0 && m == 0) return 1;
    if (n == 1 && m == 0) return 0;
    if (m == 0) return (n - 1) * (rencontresNumber(n - 1, 0) + rencontresNumber(n - 2, 0));
    return (n - 1) * (rencontresNumber(n - 1, m) + rencontresNumber(n - 2, m - 1));
}

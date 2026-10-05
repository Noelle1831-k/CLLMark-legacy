int countWays(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 3;
    int a = 1, b = 0, c = 3;
    int result;
    for (int i = 3; i <= n; i++) {
        result = c * 4 - a;
        a = b;
        b = c;
        c = result;
    }
    return result;
}
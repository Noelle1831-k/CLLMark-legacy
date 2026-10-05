int countWays(int n) {
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;
    int a = 1, b = 1, c = 2, d, i;
    for (i = 3; i <= n; i++) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}
int yearsRequired(int n) {
    int ways = countWays(n);
    int days = (ways + 9) / 10;
    int years = (days + 364) / 365;
    return years;
}
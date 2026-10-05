int getPell(int n) {
    if (n <= 2)
        return n;
    int a = 1, b = 2;
    int result;
    for (int i = 3; i <= n; i++) {
        result = 2 * b + a;
        a = b;
        b = result;
    }
    return result;
}
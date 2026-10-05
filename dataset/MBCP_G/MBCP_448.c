int calSum(int n) {
    if (n < 0) return 0;
    int a = 3, b = 0, c = 2;
    int sum = a + b + c;
    if (n == 0) return b;
    if (n == 1) return a;
    if (n == 2) return sum;
    for (int i = 3; i <= n; i++) {
        int next = a + b;
        sum += next;
        b = a;
        a = c;
        c = next;
    }
    return sum;
}
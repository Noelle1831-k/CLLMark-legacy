int apSum(int a, int n, int d) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a + i * d;
    }
    return sum;
}
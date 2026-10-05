    int sum1 = 0;
    for (int i = 1; i <= n; i++) {
        sum1 += i;
    }
    int sum2 = 0;
    for (int i = 1; i <= n; i++) {
        sum2 += i * i;
    }
    return (sum1 * sum1) - sum2;
}
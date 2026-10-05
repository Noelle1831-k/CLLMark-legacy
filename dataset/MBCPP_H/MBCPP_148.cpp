    int sum1 = 0, sum2 = 0;
    int i;
    for (i = n; i > 0; i /= 10) {
        sum1 += i % 10;
    }
    for (i = n - sum1; i > 0; i /= 10) {
        sum2 += i % 10;
    }
    return sum1 + sum2;
}
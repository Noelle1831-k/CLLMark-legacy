int sum = 0;
    for (int k = 0; k <= n; k += 2) {
        int coef = 1;
        for (int i = 0; i < k; ++i) {
            coef = coef * (n - i) / (i + 1);
        }
        sum += coef;
    }
    return sum;
}
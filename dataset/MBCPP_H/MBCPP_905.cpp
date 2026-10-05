    int res = 1;
    for (int i = n + 1; i <= n * 2; i++) {
        res = res * i;
    }
    for (int i = 1; i <= n; i++) {
        res = res / i;
    }
    return res;
}
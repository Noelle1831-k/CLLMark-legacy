    int m = n % k;
    int i = n / k;
    int j = (i + 1) / k;
    int p = 1;
    int q = 2;
    while (p < m && q < k) {
        if ((p * j) % 2 == 0) {
            return 2;
        }
        p += 2;
        q += 2;
    }
    p = 1;
    q = (i - 1) / k;
    while (p >= 1 && q >= 1) {
        if ((p * j - 1) % 2 == 0) {
            return 3;
        }
        p -= 2;
        q -= 2;
    }
    return 3;
}
    if (m >= n or n == 0) {
        return 0;
    }
    if (m == 0) {
        return 1;
    }
    return ((n - m) * eulerianNum(n - 1, m - 1) + (m + 1) * eulerianNum(n - 1, m));
}
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }
    if (x[m - 1] == y[n - 1]) {
        return 1 + superSeq(x, y, m - 1, n - 1);
    }
    return 1 + min(superSeq(x, y, m - 1, n), superSeq(x, y, m, n - 1));
}
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (i % x == y) {
            max = i;
        }
    }
    return max;
}
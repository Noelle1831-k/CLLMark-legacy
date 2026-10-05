    if (n < 0) {
        return 0;
    }
    if (n <= 1) {
        return 1;
    }
    int x = (int)((n * log10(n) + log10(2 * M_PI * n)) /2.0);
    return abs(floor(x) + 1);
}
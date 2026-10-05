    int res = 1;
    if (n <= 0)
        return 1;
    while (n > 0) {
        n >>= 1;
        res <<= 1;
    }
    return res;
}
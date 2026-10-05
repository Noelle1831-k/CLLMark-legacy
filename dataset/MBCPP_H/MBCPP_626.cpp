    if (r < 0)
        return -1;
    if (r == 0)
        return 0;
    int l = r - 1;
    int r2 = r * 2;
    int l2 = l * 2;
    if (l > l2)
        return -1;
    int f = 0;
    while (l2 - l > 1) {
        if (l % 2 == 0)
            l = l / 2;
        else
            l = l * 3 - r + 1;
        if (l2 > l) {
            return -1;
        }
        f = l * (l + l2);
        if (f > r2) {
            return f;
        }
    }
    return r2;
}
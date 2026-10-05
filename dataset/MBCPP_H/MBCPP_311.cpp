    int i;
    for (i = n; i > 0; i--) {
        int j;
        for (j = n; j > i; j--) {
            if (n & (1 << j)) {
                n |= 1 << i;
                break;
            }
        }
    }
    return n;
}
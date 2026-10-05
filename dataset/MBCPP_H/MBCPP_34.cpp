    int i;
    int k = 0;
    for (i = 0; i < n; i++) {
        if (ar[i] != i + 1) {
            return i + 1;
        }
    }
    return i;
}
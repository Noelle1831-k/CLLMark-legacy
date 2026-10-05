    if (n <= 2) {
        return n;
    }
    int i = n * 2;
    while (1) {
        for (int a = 1; a < n; a++) {
            if (i % a != 0) {
                i += n;
                break;
            }
            if (a == n - 1 && i % a == 0) {
                return i;
            }
        }
    }
}
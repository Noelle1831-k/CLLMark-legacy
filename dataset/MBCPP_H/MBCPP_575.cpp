    int count = 0;
    for (int i = l; i <= r; i++) {
        if (i % a != 0) {
            count += 1;
        }
        if (count == n) {
            return i;
        }
    }
    return -1;
}
    if (l >= r) {
        return 0;
    }
    int count = 0;
    for (int i = l; i <= r; i++) {
        int a = int(i);
        if ((a >= 10) && (a <= 15)) {
            count++;
        }
    }
    return count;
}
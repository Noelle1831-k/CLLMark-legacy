int countNum(int n) {
    int count = 0;
    for (int i = 0; i <= n; i++) {
        if ((i & 1) && (i & (1 << n))) {
            count++;
        }
    }
    return count;
}
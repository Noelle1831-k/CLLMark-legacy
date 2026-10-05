int findNthDigit(int p, int q, int n) {
    p = p % q;
    for (int i = 0; i < n - 1; i++) {
        p = (p * 10) % q;
    }
    return (p * 10) / q;
}
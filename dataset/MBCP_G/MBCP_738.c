double geometricSum(int n) {
    if (n == 0) {
        return 1;
    }
    return 1.0 / (1 << (n - 1)) + geometricSum(n - 1);
}
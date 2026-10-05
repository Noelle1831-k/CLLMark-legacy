function geometricSum(n) {
    if (n < 0) {
        return 0;
    }
    return 1.0 / (Math.pow(2, n)) + geometricSum(n - 1);
}

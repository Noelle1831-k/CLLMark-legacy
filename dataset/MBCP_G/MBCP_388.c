int highestPowerOf2(int n) {
    int res = 1;
    while (res * 2 <= n) {
        res *= 2;
    }
    return res;
}
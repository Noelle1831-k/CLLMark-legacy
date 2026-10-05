int findMaxVal(int n, int x, int y) {
    if (y >= x) return -1;
    int result = n - (n % x) + y;
    if (result > n) result -= x;
    return result;
}
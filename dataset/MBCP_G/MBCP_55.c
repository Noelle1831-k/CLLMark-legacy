int tnGp(int a, int n, int r) {
    int result = a;
    for (int i = 1; i < n; i++) {
        result *= r;
    }
    return result;
}
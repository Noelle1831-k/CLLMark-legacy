bool difSquare(int n) {
    if (n < 0) return false;
    for (int a = 0; a * a <= n + n; ++a) {
        for (int b = 0; b <= a; ++b) {
            if (a * a - b * b == n) {
                return true;
            }
        }
    }
    return false;
}
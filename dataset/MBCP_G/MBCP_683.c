bool sumSquare(int n) {
    for (int i = 0; i <= sqrt(n); ++i) {
        int j = sqrt(n - i * i);
        if (i * i + j * j == n) {
            return true;
        }
    }
    return false;
}
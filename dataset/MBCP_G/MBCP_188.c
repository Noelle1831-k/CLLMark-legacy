bool prodSquare(int n) {
    int limit = (int)sqrt(n);
    for (int i = 0; i <= limit; ++i) {
        if (i * i == n) {
            return true;
        }
        for (int j = 0; j <= limit; ++j) {
            if (i * i * j * j == n) {
                return true;
            }
        }
    }
    return false;
}
int multiplyInt(int x, int y) {
    int result = 0;
    bool negative = false;
    if (y < 0) {
        y = -y;
        negative = true;
    }
    for (int i = 0; i < y; i++) {
        result += x;
    }
    return negative ? -result : result;
}
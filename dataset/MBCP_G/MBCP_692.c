int lastTwoDigits(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
        while (result % 10 == 0) {
            result /= 10;
        }
        result %= 100;
    }
    return result;
}
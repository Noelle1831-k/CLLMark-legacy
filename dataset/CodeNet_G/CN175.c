int decimalToQuaternary(int n) {
    if (n == 0) return 0;
    int base = 1;
    int quaternaryNum = 0;
    while (n > 0) {
        int remainder = n % 4;
        n = n / 4;
        quaternaryNum += remainder * base;
        base *= 10;
    }
    return quaternaryNum;
}
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }
    int lastDigit = 0;
    while (a > 1) {
        lastDigit = lastDigit + a % b;
        a = a / b;
    }
    return lastDigit;
}
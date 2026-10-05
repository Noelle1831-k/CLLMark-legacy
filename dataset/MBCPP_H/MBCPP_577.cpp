    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (n > 9) {
        return 0;
    }
    return lastDigitFactorial(n / 10) * (n % 10);
}
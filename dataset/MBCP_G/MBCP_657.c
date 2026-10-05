int firstDigit(int n) {
    double logSum = 0;
    for (int i = 1; i <= n; i++) {
        logSum += log10(i);
    }
    double fractionalPart = logSum - floor(logSum);
    return (int) pow(10, fractionalPart);
}
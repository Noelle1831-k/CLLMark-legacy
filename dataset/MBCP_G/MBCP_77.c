bool isDiff(int n) {
    int evenSum = 0, oddSum = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) {
            evenSum += digit;
        } else {
            oddSum += digit;
        }
        n /= 10;
    }
    return evenSum > oddSum;
}
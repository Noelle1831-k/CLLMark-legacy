bool isNumKeith(int x) {
    int temp = x, numDigits = (int)log10(x) + 1;
    int digits[numDigits];
    for (int i = numDigits - 1; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }
    int sum, i;
    while (1) {
        sum = 0;
        for (i = 0; i < numDigits; i++) {
            sum += digits[i];
        }
        if (sum == x) return true;
        if (sum > x) return false;
        for (i = 0; i < numDigits - 1; i++) {
            digits[i] = digits[i + 1];
        }
        digits[numDigits - 1] = sum;
    }
}
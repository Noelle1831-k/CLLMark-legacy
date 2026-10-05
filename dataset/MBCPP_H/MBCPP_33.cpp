    if (n == 0) {
        return 0;
    } else if (n < 0) {
        return 1 + decimalToBinary(-n);
    } else {
        return (10 * decimalToBinary(n / 2)) + (n % 2);
    }
}
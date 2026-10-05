int decimalToBinary(int n) {
    int binary = 0;
    int base = 1;
    while (n > 0) {
        int last_digit = n % 2;
        n = n / 2;
        binary = binary + last_digit * base;
        base = base * 10;
    }
    return binary;
}
int binaryToDecimal(int binary) {
    int decimal = 0;
    int base = 1;
    while (binary > 0) {
        int last_digit = binary % 10;
        binary = binary / 10;
        decimal += last_digit * base;
        base = base * 2;
    }
    return decimal;
}
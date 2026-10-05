int computeLastDigit(int a, int b) {
    if (a == b) return 1;
    int last_digit = 1;
    for (int i = a + 1; i <= b; i++) {
        last_digit = (last_digit * i) % 10;
    }
    return last_digit;
}
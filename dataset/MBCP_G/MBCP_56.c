bool check(int n) {
    int reverse = 0, original = n;
    while (n > 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return original == 2 * reverse - 1;
}
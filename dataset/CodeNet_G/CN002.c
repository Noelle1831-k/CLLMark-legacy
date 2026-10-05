int digit_count(int a, int b) {
    int sum = a + b;
    if (sum == 0) {
        return 1;
    }
    return (int)log10(sum) + 1;
}
void calculate_sums(int a, int b, int n) {
    int s, i, fractional_part;
    s = 0;
    a = a % b;
    for (i = 0; i < n; i++) {
        a *= 10;
        fractional_part = a / b;
        s += fractional_part;
        a %= b;
    }
    printf("%d\n", s);
}

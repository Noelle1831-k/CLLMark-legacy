void calculate_area(int d) {
    long long area = 0;
    for (int i = 0; i < 600; i += d) {
        area += i * i * d;
    }
    printf("%lld\n", area);
}
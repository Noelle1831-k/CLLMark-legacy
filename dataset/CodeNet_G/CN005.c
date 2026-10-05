long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}
void processInput() {
    long long a, b;
    while (scanf("%lld %lld", &a, &b) != EOF) {
        printf("%lld %lld\n", gcd(a, b), lcm(a, b));
    }
}
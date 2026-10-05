int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int smallestMultiple(int n) {
    int lcm = 1;
    for (int i = 2; i <= n; i++) {
        lcm = (lcm * i) / gcd(lcm, i);
    }
    return lcm;
}
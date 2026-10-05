int gcd(int a, int b, int *steps) {
    *steps = 0;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
        (*steps)++;
    }
    return a;
}
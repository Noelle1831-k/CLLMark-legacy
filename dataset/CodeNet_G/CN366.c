int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int calculate_minimum_d(int *t, int n) {
    int g = t[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, t[i]);
    }
    int sum_d = 0;
    for (int i = 0; i < n; i++) {
        sum_d += (g - t[i] % g) % g;
    }
    return sum_d;
}
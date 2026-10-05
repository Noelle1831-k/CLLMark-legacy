int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
int lcm_of_all(int *p, int n) {
    int l = p[0];
    for (int i = 1; i < n; i++) {
        l = lcm(l, p[i]);
    }
    return l;
}
int count_combinations(int n, int *p) {
    int total = 0;
    int combinations = 1 << n;
    for (int i = 1; i < combinations; i++) {
        int current_lcm = 1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                current_lcm = lcm(current_lcm, p[j]);
            }
        }
        if (current_lcm == lcm_of_all(p, n)) {
            total++;
        }
    }
    return total;
}
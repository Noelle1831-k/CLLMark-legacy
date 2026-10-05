int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
void answer(int l, int r, int* result) {
    for (int i = l; i <= r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
            int lcm_val = lcm(i, j);
            if (lcm_val >= l && lcm_val <= r) {
                result[0] = i;
                result[1] = j;
                return;
            }
        }
    }
    result[0] = -1;
    result[1] = -1;
}
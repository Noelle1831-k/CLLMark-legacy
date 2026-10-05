long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}
void solve(int n, long long d[], long long v[]) {
    long long t[10];
    long long common_time;
    for (int i = 0; i < n; ++i) {
        t[i] = d[i] * v[i];
    }
    common_time = t[0];
    for (int i = 1; i < n; ++i) {
        common_time = lcm(common_time, t[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%lld\n", common_time / t[i]);
    }
}
int main() {
    int n;
    long long d[10], v[10];
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; ++i) {
            scanf("%lld %lld", &d[i], &v[i]);
        }
        solve(n, d, v);
    }
    return 0;
}
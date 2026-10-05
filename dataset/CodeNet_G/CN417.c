#define MAX_N 100000
#define MAX_K 11
long long pow_mod(long long a, long long b, long long m) {
    long long result = 1;
    long long base = a % m;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        b /= 2;
    }
    return result;
}
int main() {
    int N, K;
    long long M;
    scanf("%d %d %lld", &N, &K, &M);
    long long total = pow_mod(K, N, M);
    long long good_series = K;
    for (int i = 2; i <= N; ++i) {
        good_series *= K;
        good_series %= M;
    }
    long long bad_series = (total - good_series + M) % M;
    printf("%lld\n", bad_series);
    return 0;
}

#define MODULO 1000000007
unsigned long long mod_factorial(int n) {
    if (n == 0) return 1;
    unsigned long long res = 1;
    for (int i = 1; i <= n; ++i) {
        res = (res * i) % MODULO;
    }
    return res;
}
int main() {
    while (1) {
        int N, R;
        if (scanf("%d", &N) != 1 || N == 0) break;
        scanf("%d", &R);
        int *perm = malloc(N * sizeof(int));
        for (int i = 0; i < N; ++i) {
            perm[i] = i;
        }
        for (int i = 0; i < R; ++i) {
            int s, t;
            scanf("%d %d", &s, &t);
            int temp = perm[s - 1];
            perm[s - 1] = perm[t - 1];
            perm[t - 1] = temp;
        }
        unsigned long long factor = mod_factorial(N);
        unsigned long long position = 0;
        for (int i = 0; i < N; ++i) {
            factor = factor * mod_factorial(N - i - 1) % MODULO;
            for (int j = i + 1; j < N; ++j) {
                if (perm[j] < perm[i]) {
                    position = (position + factor) % MODULO;
                }
            }
        }
        printf("%llu\n", position);
        free(perm);
    }
    return 0;
}
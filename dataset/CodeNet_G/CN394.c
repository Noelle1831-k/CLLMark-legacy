#define MOD 1000000007
long long total_salary(int N, int M, long long D, int *s, int *t, int *f) {
    long long total_pay = 0;
    int current_salary[N];
    for (int i = 0; i < N; i++) {
        current_salary[i] = s[i];
    }
    for (long long d = 0; d < D; d++) {
        for (int j = 0; j < N; j++) {
            int staff_id = (j + d) % N;
            total_pay = (total_pay + (long long)current_salary[staff_id] * t[j]) % MOD;
        }
        int promotion_id = d % N;
        int factor_id = d % M;
        current_salary[promotion_id] += f[factor_id];
    }
    return total_pay;
}

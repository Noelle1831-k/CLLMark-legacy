#define MAX_N 30
#define MAX_X 1000000
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
bool is_divisible_by_any(int num, int *divisors, int divisor_count) {
    for (int i = 0; i < divisor_count; ++i) {
        if (divisors[i] != 0 && num % divisors[i] == 0) {
            return true;
        }
    }
    return false;
}
int max_nondivisible_sum(int *values, int n, int budget) {
    bool dp[MAX_X + 1] = {false};
    int divisors[MAX_X + 1] = {0};
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = budget - values[i]; j >= 0; --j) {
            if (dp[j]) {
                dp[j + values[i]] = true;
            }
        }
    }
    for (int i = 2; i <= budget; ++i) {
        for (int j = i; j <= budget; j += i) {
            if (dp[j]) {
                divisors[j] = gcd(divisors[j], i);
            }
        }
    }
    for (int i = budget; i > 1; --i) {
        if (dp[i] && !is_divisible_by_any(i, divisors, budget)) {
            return i;
        }
    }
    return -1;
}
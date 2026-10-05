#define MAX_MP 999983
int primes[MAX_MP + 1];
int prime_count;
void sieve_of_eratosthenes() {
    memset(primes, 0, sizeof(primes));
    prime_count = 0;
    for (int i = 2; i <= MAX_MP; i++) {
        if (primes[i] == 0) {
            primes[prime_count++] = i;
            for (int j = i * 2; j <= MAX_MP; j += i) {
                primes[j] = 1;
            }
        }
    }
}
int count_primes_in_range(int p, int m) {
    int count = 0;
    int lower_bound = p - m;
    int upper_bound = p + m;
    for (int i = 0; i < prime_count && primes[i] <= upper_bound; i++) {
        if (primes[i] >= lower_bound) {
            count++;
        }
    }
    return count;
}
int calculate_royalty_fee(int n, int *data) {
    int total_fee = 0;
    for (int i = 0; i < n; i++) {
        int p = data[i * 2];
        int m = data[i * 2 + 1];
        int x = count_primes_in_range(p, m);
        if (x > 1) {
            total_fee += x - 1;
        }
    }
    return total_fee;
}
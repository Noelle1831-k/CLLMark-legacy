#define MAX 50000
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}
void sieve_of_eratosthenes(bool prime[], int n) {
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
void find_goldbach_combinations(int n) {
    int count = 0;
    bool prime[MAX + 1];
    for (int i = 0; i <= MAX; i++) prime[i] = true;
    sieve_of_eratosthenes(prime, n);
    if (n % 2 == 0) {
        for (int i = 2; i <= n / 2; i++) {
            if (prime[i] && prime[n - i]) {
                count++;
            }
        }
    }
    printf("%d\n", count);
}
int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        find_goldbach_combinations(n);
    }
    return 0;
}
#define MAX 1000000
bool is_prime[MAX + 1];
void sieve_of_eratosthenes() {
    for(int i = 2; i <= MAX; i++) {
        is_prime[i] = true;
    }
    for(int i = 2; i <= sqrt(MAX); i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
int goldbach_pairs(int n) {
    int count = 0;
    for(int i = 2; i <= n / 2; i++) {
        if(is_prime[i] && is_prime[n - i]) {
            count++;
        }
    }
    return count;
}
int main() {
    sieve_of_eratosthenes();
    int n;
    while(scanf("%d", &n) && n != 0) {
        printf("%d\n", goldbach_pairs(n));
    }
    return 0;
}
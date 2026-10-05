#define MAX_N 10000010
bool is_prime[MAX_N];
void sieve() {
    for (int i = 0; i < MAX_N; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX_N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
int max_quadruplet_size(int n) {
    int max_size = 0;
    for (int a = 3; a <= n - 8; a += 2) {
        if (is_prime[a] && is_prime[a + 2] && is_prime[a + 6] && is_prime[a + 8]) {
            if (a + 8 <= n) {
                max_size = a + 8;
            }
        }
    }
    return max_size;
}
int main() {
    sieve();
    return 0;
}
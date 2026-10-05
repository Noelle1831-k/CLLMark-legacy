bool is_prime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}
int count_primes(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            count++;
        }
    }
    return count;
}
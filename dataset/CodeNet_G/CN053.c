bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int sum_of_primes(int n) {
    int count = 0, sum = 0, current = 2;
    while (count < n) {
        if (is_prime(current)) {
            sum += current;
            count++;
        }
        current++;
    }
    return sum;
}
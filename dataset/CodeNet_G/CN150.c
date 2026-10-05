int is_prime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
void find_largest_twin_prime(int n) {
    int last_prime = 0, current_prime = 0;
    for (int i = 5; i <= n; i++) {
        if (is_prime(i)) {
            if (i - last_prime == 2) {
                current_prime = i;
            }
            last_prime = i;
        }
    }
    printf("%d %d\n", current_prime - 2, current_prime);
}
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}
void find_primes(int n) {
    int lower = n - 1;
    while (lower >= 2 && !is_prime(lower)) {
        lower--;
    }
    int upper = n + 1;
    while (!is_prime(upper)) {
        upper++;
    }
    printf("%d %d\n", lower, upper);
}

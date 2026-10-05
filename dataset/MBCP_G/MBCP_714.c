int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}
int countFac(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            count++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1 && isPrime(n)) {
        count++;
    }
    return count;
}